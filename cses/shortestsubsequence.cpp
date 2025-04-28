#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    deque<int> a, c, g, t;

    // Populate the deques based on the character in the string
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a.push_back(i);
        if (s[i] == 'C') c.push_back(i);
        if (s[i] == 'G') g.push_back(i);
        if (s[i] == 'T') t.push_back(i);
    }

    // Append n to each deque as the terminal marker
    a.push_back(n);
    c.push_back(n);
    g.push_back(n);
    t.push_back(n);

    int idx = -1;
    string ans;

    // Construct the answer string
    while (idx < n) {
        while (!a.empty() && a.front() <= idx) a.pop_front();
        while (!c.empty() && c.front() <= idx) c.pop_front();
        while (!g.empty() && g.front() <= idx) g.pop_front();
        while (!t.empty() && t.front() <= idx) t.pop_front();

        vector<pair<int, char>> cur = {
            {a.front(), 'A'},
            {c.front(), 'C'},
            {g.front(), 'G'},
            {t.front(), 'T'}
        };

        auto max_pair = *max_element(cur.begin(), cur.end());
        idx = max_pair.first;
        ans += max_pair.second;
    }

    cout << ans << endl;

    return 0;
}

