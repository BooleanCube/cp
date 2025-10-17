#!/usr/bin/env python3
"""
CSES Solutions Downloader
Downloads all accepted solutions from CSES and organizes them in a git repository
"""

import re
import time
import requests
from bs4 import BeautifulSoup
from pathlib import Path

import os
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()


class CSESSolutionDownloader:
    def __init__(self, username, password):
        self.username = username
        self.password = password
        self.session = requests.Session()
        self.base_url = "https://cses.fi"
        self.solutions_dir = Path("cses")

    def login(self):
        """Login to CSES"""
        print("Logging in to CSES...")

        # Get CSRF token
        login_page = self.session.get(f"{self.base_url}/login")
        soup = BeautifulSoup(login_page.text, 'html.parser')
        csrf_token = soup.find('input', {'name': 'csrf_token'})['value']

        # Login
        login_data = {
            'csrf_token': csrf_token,
            'nick': self.username,
            'pass': self.password
        }

        response = self.session.post(f"{self.base_url}/login", data=login_data)

        if "Login failed" in response.text:
            raise Exception("Login failed! Check your credentials.")

        print("Successfully logged in!")
        return True

    def get_problem_list(self):
        """Get list of all problems with their categories"""
        print("Fetching problem list...")

        problemset_page = self.session.get(f"{self.base_url}/problemset")
        soup = BeautifulSoup(problemset_page.text, 'html.parser')

        problems = []
        current_category = ""

        for element in soup.find_all(['h2', 'li']):
            if element.name == 'h2':
                current_category = element.text.strip()
            elif element.name == 'li' and element.find('a'):
                link = element.find('a')
                if '/problemset/task/' in link.get('href', ''):
                    problem_id = link['href'].split('/')[-1]
                    problem_name = link.text.strip()

                    # Check if solved (has green checkmark)
                    if 'task-score icon full' in str(element).split("<li")[1]:
                        problems.append({
                            'id': problem_id,
                            'name': problem_name,
                            'category': current_category,
                            'url': f"{self.base_url}{link['href']}"
                        })

        print(f"Found {len(problems)} solved problems")
        return problems

    def get_accepted_solution(self, problem_id):
        """Get the latest accepted solution for a problem"""
        result_page = self.session.get(f"{self.base_url}/problemset/view/{problem_id}/")
        soup = BeautifulSoup(result_page.text, 'html.parser')

        # Find accepted submissions
        submissions = soup.find_all('tr')

        # print(submissions)

        for submission in submissions:
            if 'task-score icon full' in str(submission):
                # Get submission ID
                submission_link = submission.find('a')
                if submission_link and '/problemset/result/' in submission_link.get('href', ''):
                    submission_url = submission_link.get('href', '')
                    return self.get_submission_code(submission_url)

        return None

    def get_submission_code(self, submission_url):
        """Download the actual code for a submission"""
        submission_page = self.session.get(f"{self.base_url}{submission_url}")

        if submission_page.status_code == 200:
            # Extract code from the page
            soup = BeautifulSoup(submission_page.text, 'html.parser')
            pre_elements = soup.find_all('pre')

            for pre in pre_elements:
                if pre and 'linenums' in str(pre):
                    return pre.text

        return None

    def determine_file_extension(self, code):
        """Determine file extension based on code content"""
        if '#include' in code:
            return '.cpp'
        elif 'import java' in code or 'public class' in code:
            return '.java'
        elif 'def ' in code or 'import ' in code or 'print(' in code:
            return '.py'
        elif '#include <stdio.h>' in code:
            return '.c'
        elif 'fn main()' in code:
            return '.rs'
        elif 'package main' in code:
            return '.go'
        elif 'const ' in code or 'let ' in code or 'var ' in code:
            return '.js'
        else:
            return '.cpp'  # Default to C++

    def sanitize_filename(self, name):
        """Convert problem name to valid filename"""
        # Remove special characters and replace spaces
        name = re.sub(r'[^\w\s-]', '', name)
        name = re.sub(r'[-\s]+', '_', name)
        return name.lower()

    def save_solution(self, problem, code):
        """Save solution to appropriate directory"""
        if not code:
            return False

        # Create category directory
        category_dir = self.solutions_dir / self.sanitize_filename(problem['category'])
        category_dir.mkdir(parents=True, exist_ok=True)

        # Determine filename
        filename = f"{self.sanitize_filename(problem['name'])}"
        extension = self.determine_file_extension(code)
        filepath = category_dir / f"{filename}{extension}"

        # Save code
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(code)

        return True

    def create_readme(self, problems):
        """Create README.md with problem list and statistics"""
        readme_content = "# CSES Problem Set Solutions\n\n"
        readme_content += f"This repository contains my accepted solutions for {len(problems)} problems from the CSES Problem Set.\n\n"

        # Group by category
        categories = {}
        for p in problems:
            if p['category'] not in categories:
                categories[p['category']] = []
            categories[p['category']].append(p)

        # Statistics
        readme_content += "## Statistics\n\n"
        readme_content += "| Category | Solved |\n"
        readme_content += "|----------|--------|\n"

        for category, probs in sorted(categories.items()):
            readme_content += f"| {category} | {len(probs)} |\n"

        readme_content += f"| **Total** | **{len(problems)}** |\n\n"

        # Problem list
        readme_content += "## Problems\n\n"

        for category, probs in sorted(categories.items()):
            readme_content += f"### {category}\n\n"
            for p in sorted(probs, key=lambda x: x['name']):
                readme_content += f"- [{p['name']}]({p['url']}) - `{p['id']}`\n"
            readme_content += "\n"

        # Save README
        with open(self.solutions_dir / "README.md", 'w') as f:
            f.write(readme_content)


    def download_all(self):
        """Main method to download all solutions"""
        try:
            # Login
            self.login()

            # Get problems
            problems = self.get_problem_list()

            if not problems:
                print("No solved problems found!")
                return

            # Create solutions directory
            self.solutions_dir.mkdir(exist_ok=True)

            # Download solutions
            print(f"\nDownloading solutions...")
            success_count = 0

            for i, problem in enumerate(problems, 1):
                print(f"[{i}/{len(problems)}] Downloading {problem['name']}...", end=' ')

                # Get Category Directory
                category_dir = self.solutions_dir / self.sanitize_filename(problem['category'])

                # Determine filename
                filename = f"{self.sanitize_filename(problem['name'])}"
                if os.path.exists(category_dir/f"{filename}.py") or os.path.exists(category_dir/f"{filename}.cpp") or os.path.exists(category_dir/f"{filename}.java"):
                    print("✓")
                    success_count += 1
                    continue

                code = self.get_accepted_solution(problem['id'])
                if self.save_solution(problem, code):
                    print("✓")
                    success_count += 1
                else:
                    print("✗ (Could not retrieve solution)")

                # Be nice to the server
                time.sleep(0.5)

            print(f"\nSuccessfully downloaded {success_count}/{len(problems)} solutions")

            # Create README
            self.create_readme(problems)
            print("Created README.md")

            # Initialize git

        except Exception as e:
            print(f"Error: {e}")


def main():
    print("CSES Solutions Downloader")
    print("=" * 30)

    # Get credentials
    username = os.getenv("nick")
    password = os.getenv("pass")

    # Create downloader and run
    downloader = CSESSolutionDownloader(username, password)
    downloader.download_all()


if __name__ == "__main__":
    main()
