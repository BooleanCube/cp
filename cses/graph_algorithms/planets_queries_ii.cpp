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
#define endl '\n'
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

/*  All Rcuruired define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;


int n, q;

vi t, vis, dep, ans;
vector<vi> radj;
vector<vector<pii>> qs;

void cycle(vi &c, int x) {
  int u = x, v = t[x];
  while(u != v) u = t[u], v = t[t[v]];
  int cur = u;
  int cd = 0;
  while(c.empty() || u != cur) {
    c.pb(cur);
    dep[cur] = -cd; cd++;
    cur = t[cur];
  }
}

void dfs(int u, int d) {
  vis[u] = 1;
  int pd = dep[u];
  dep[u] = d;
  for(auto [v, i] : qs[u]) ans[i] = (dep[v] > -INF) ? d - dep[v] : -1;
  for(int v : radj[u]) {
    if(vis[v]) continue;
    dfs(v, d+1);
  }
  dep[u] = pd;
}

void solve() {
  cin >> n >> q;

  t = vis = vi(n);
  dep = vi(n, -INF);
  radj = vector<vi>(n);
  qs = vector<vector<pii>>(n);
  ans = vi(q);

  afr(t) cin >> u, u--;
  frn(i, q) {
    int u, v; cin >> u >> v; u--, v--;
    qs[u].pb({v, i});
  }
  frn(i, n) radj[t[i]].pb(i);

  frn(i, n) {
    if(vis[i]) continue;
    vi c; cycle(c, i);
    dfs(c[0], 0);
    afr(c) dep[u] = -INF;
  }

  afr(ans) cout << u << endl;

  return;
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

