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
const ll INF = 1e16;
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
#define fr(i,s,e) for(long long int i=(s);i<(e);i++)
#define frn(i,n) fr(i,0,(n))
#define cfr(i,s,e) for(long long int i=(s);i<=(e);i++)
#define rfr(i,e,s) for(long long int i=(e)-1;i>=(s);i--)
#define afr(a) for(auto u:a)
#define pb push_back
#define eb emplace_back

/* DEBUGGING && PRINTING */
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f sp u.s<<endl;}

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;


vector<vector<pll>> graph;
vll dist;
vi vis;

bool dfs(int cur, int target) {
    if(cur == target) return 1;
    if(vis[cur]) return 0;
    vis[cur]++;
    int flag = 0;
    for(auto [nbr, wt] : graph[cur]) {
        if(vis[nbr]) continue;
        flag |= dfs(nbr, target);
    }
    return flag;
}

void solve() {
    int n, m; cin >> n >> m;
    graph = vector<vector<pll>>(n);
    frn(i, m) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--, w *= -1;
        graph[a].pb({b, w});
    }
    dist = vll(n, INF); dist[0] = 0;
    frn(i, n-1)
        frn(j, n)
            for(auto [nbr, wt] : graph[j]) 
                dist[nbr] = min(dist[nbr], dist[j]+wt);
    si aff;
    frn(i, n) {
        frn(j, n) {
            for(auto [nbr, wt] : graph[j]) {
                if(dist[nbr] > dist[j] + wt) {
                    aff.insert(nbr);
                    dist[nbr] = dist[j] + wt;
                }
            }
        }
    }
    int flag = 0;
    for(int s : aff) {
        vis = vi(n);
        int a = dfs(0, s);
        vis = vi(n);
        int b = dfs(s, n-1);
        flag |= a & b;
    }
    if(flag || dist[n-1] == INF) cout << -1 << endl;
    else cout << -dist[n-1] << endl;
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

