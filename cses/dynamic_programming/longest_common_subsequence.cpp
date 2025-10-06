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
#define sp << " " <<
#define endl '\n'
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll HMOD = 998244353;
const ll INF = 1e9;
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
 
/* UTILS */
#define read(type) readInt<type>()
ll min(ll a, int b) {
  if (a < b)
    return a;
  return b;
}
ll min(int a, ll b) {
  if (a < b)
    return a;
  return b;
}
ll max(ll a, int b) {
  if (a > b)
    return a;
  return b;
}
ll max(int a, ll b) {
  if (a > b)
    return a;
  return b;
}
ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z')
      a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z')
      a[i] += 'a' - 'A';
  return a;
}
bool prime(ll a) {
  if (a == 1)
    return 0;
  for (int i = 2; i <= round(sqrt(a)); ++i)
    if (a % i == 0)
      return 0;
  return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
 
/* FUNCTIONS */
#define sz(a) ((int)a.size())
#define all(a) (a).begin(), (a).end()
#define fr(i, s, e) for (ll i = (s); i < (e); i++)
#define frn(i, n) fr(i, 0, (n))
#define cfr(i, s, e) for (ll i = (s); i <= (e); i++)
#define rfr(i, e, s) for (ll i = (e) - 1; i >= (s); i--)
#define afr(a) for (auto &u : a)
#define pb push_back
#define eb emplace_back
 
/* DEBUGGING && PRINTING */
#define printv(a)                                                              \
  {                                                                            \
    for (auto u : a)                                                           \
      cout << u << " ";                                                        \
    cout << endl;                                                              \
  }
#define printm(a)                                                              \
  {                                                                            \
    for (auto u : a)                                                           \
      cout << u.f sp u.s << endl;                                              \
  }
 
/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
 
int n, m;
vi a, b;
vector<vi> memo;
 
int dp(int i, int j) {
  if (i >= n || j >= m)
    return 0;
  if (memo[i][j] != -1)
    return memo[i][j];
  if (a[i] == b[j])
    return memo[i][j] = dp(i + 1, j + 1) + 1;
  return memo[i][j] = max(dp(i + 1, j), dp(i, j + 1));
}
 
void solve() {
  cin >> n >> m;
  a = vi(n), b = vi(m);
  afr(a) cin >> u;
  afr(b) cin >> u;
  memo = vector<vi>(n, vi(m, -1));
  cout << dp(0, 0) << endl;
  vi ans;
  int cur = memo[0][0], li = 0, lj = 0;
outer:
  while (cur > 0) {
    fr(i, li, n) {
      fr(j, lj, m) {
        if (a[i] == b[j] && memo[i][j] == cur) {
          cur--;
          ans.pb(a[i]);
          li = i+1, lj = j+1;
          goto outer;
        }
      }
    }
  }
  printv(ans);
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
  int tc = 1;
  // cin >> tc;
  cfr(t, 1, tc) {
    // cout << "Case #" << t << ": ";
    solve();
  }
}