# cp

all of my competitive programming solutions

## setup

```bash
# setup py venv for scrapers
python -m venv .venv

# install deps for scrapers
source .venv/bin/activate
pip install -r requirements.txt

# run scrapers
## create .env file with `nick` for cses username and `pass` for cses password.
source .venv/bin/activate
python scraper_cses.py
```
