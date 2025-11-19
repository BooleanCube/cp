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
// #define si set<int>
#define sc set<char>

/* CONSTANTS */
#define f first
#define s second
#define sp <<" "<<
// #define endl '\n'
const int MAXN = 1e5+5;
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
#define printmm(a) {for(auto u:a) cout<<u.f sp u.s.f sp u.s.s sp 's'<<endl;}


/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;


int n;
vector<string> grid;
vector<vi> vis;

int valid(int i, int j) { return 0<=i && i<n && 0<=j && j<n; }

pair<string, pii> bfs(int si, int sj) {
  string ans = "";
  deque<pii> q; q.pb({si, sj});
  while(sz(q)) {
    // cout << sz(q) << endl;
    char mn = 'Z';
    vector<pair<char, pii>> cL;
    while(sz(q)) {
      auto [i, j] = q.front();
      if(i == n-1 && j == n-1) goto leave;
      q.pop_front();
      if(i < n-1 && !vis[i+1][j]) {
        vis[i+1][j] = 1;
        mn = min(mn, grid[i+1][j]), cL.pb({grid[i+1][j], {i+1, j}});
      }
      if(j < n-1 && !vis[i][j+1]) {
        vis[i][j+1] = 1;
        mn = min(mn, grid[i][j+1]), cL.pb({grid[i][j+1], {i, j+1}});
      }
    }
    int cnt = 0;
    afr(cL) if(u.f == mn) cnt++, q.pb(u.s);
    if(cnt == 1) break;
    ans += mn;
  }
leave:
  return {ans, *q.begin()};
}

void solve() {
  cin >> n;
  grid = vector<string>(n); afr(grid) cin >> u;
  vis = vector<vi>(n, vi(n));
  string ans = "";
  int i = 0, j = 0;
  while(sz(ans) < n + n - 1) {
    ans += grid[i][j];
    auto [cur, ns] = bfs(i, j);
    ans += cur; i = ns.f, j = ns.s;
  }
  // ans.pop_back();
  cout << ans << endl;
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

