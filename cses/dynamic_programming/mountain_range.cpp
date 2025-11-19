#include <bits/stdc++.h>
using namespace std;


/* TYPES  */
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* CONSTANTS */
#define f first
#define s second
#define sp <<" "<<
// #define endl '\n'
const int MAXN = 2e5+5;
const ll MOD = 1e9+7;
const ll HMOD = 998244353;
const ll INF = 1e9;
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

/* UTILS */
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/* FUNCTIONS */
#define sz(a) ((int)a.size())
#define all(a) (a).begin(), (a).end()
#define fr(i,s,e) for(ll i=(s);i<(e);i++)
#define frn(i,n) fr(i,0,(n))
#define cfr(i,s,e) for(ll i=(s);i<=(e);i++)
#define rfr(i,e,s) for(ll i=(e)-1;i>=(s);i--)
#define afr(a) for(auto &u:a)
#define pb push_back
#define eb emplace_back

/* DEBUGGING && PRINTING */
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f sp u.s<<endl;}

/*  All Rcuruired define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;


int n;
vi a, memo;
vector<array<int, 5>> r;

void update(int idx, int val) {
  idx += n;
  memo[idx] = val;
  while(idx) {
    idx >>= 1;
    memo[idx] = max(memo[idx*2], memo[idx*2+1]);
  }
}

int query(int l, int r, int t) {
  if(l == r) return max(memo[l], t);
  if(l & 1) return query(l+1, r, max(t, memo[l]));
  if(!(r & 1)) return query(l, r-1, max(t, memo[r]));
  return query(l >> 1, r >> 1, t);
}

int query(int l, int r) { return query(l+n, r+n, 0); }

void solve() {
  cin >> n;
  a = vi(n); afr(a) cin >> u;
  memo = vi(2*n, -1);
  si ci; set<pii> sa; frn(i, n) sa.insert({a[i], i});

  while(sz(ci) < n) {
    auto it = (--sa.end()); sa.erase(it);
    auto [val, sidx] = *it; ci.insert(sidx);
    vi cur(1, sidx);
    while(sz(sa)) {
      auto it = (--sa.end());
      if(it->f != val) break;
      ci.insert(it->s); cur.pb(it->s); sa.erase(it);
    }
    for(int idx : cur) {
      // cout << val sp idx << endl;
      ci.erase(idx);
      auto lB = ci.lower_bound(idx), rB = ci.lower_bound(idx);
      int lR = lB == ci.begin() ? 0 : *(--lB) + 1, rR = rB == ci.end() ? n-1 : *rB - 1;
      r.pb({rR - lR, val, idx, lR, rR});
      ci.insert(idx);
      // cout << rR-lR sp idx sp lR sp rR << endl;
    }
  }

  sort(all(r));
  for(auto [rng, v, i, lR, rR] : r) {
    if(!rng) update(i, 1);
    else update(i, query(lR, rR) + 1);
  }

  cout << memo[1] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc = 1;
  // cin >> tc;
  cfr(t, 1, tc) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}

