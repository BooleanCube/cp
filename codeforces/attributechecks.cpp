#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
using namespace __gnu_pbds;


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
ll min(int a,ll b) { if (a<b) return a; return b; } ll max(ll a,int b) { if (a>b) return a; return b; } ll max(int a,ll b) { if (a>b) return a; return b; }
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

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;


struct multiost {
    typedef tree<
        pii,
        null_type,
        less<pii>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ost;

    ost s;
    unsigned cnt = 0;

    multiost() = default;
    multiost(initializer_list<int> l) { for(int x : l) insert(x); }
    void insert(int x) { s.insert({x, cnt++}); }
    ost::iterator find_by_order(int k) { return s.find_by_order(k); }
    int order_of_key(int k) { return s.order_of_key({k, 0}); }
    void erase(int x) {
        auto it = s.lower_bound({x, 0});
        // erase(it); // erases only first element
        while(it != s.end() && it->first == x) erase(it++); // erases all elements
    }
    void erase(ost::iterator it) { s.erase(it); }
    size_t size() const { return s.size(); }
    void printo() {
        for(auto it : s) cout << it.first << " ";
        cout << endl;
    }
};

int n, m;
vi r, z;
vector<pair<multiost, multiost>> checks;
vector<map<pii, int>> memo;

int dp(int idx, int sp, int ip) {
    if(idx == m) return 0;
    if(memo[idx].count({sp, ip})) return memo[idx][{sp, ip}];
    int sp0cnt = checks[idx].f.order_of_key(sp+1);
    int sp1cnt = checks[idx].f.order_of_key(sp+2);
    int ip0cnt = checks[idx].s.order_of_key(ip+1);
    int ip1cnt = checks[idx].s.order_of_key(ip+2);
    int ans = dp(idx+1, sp, ip+1) + sp0cnt + ip1cnt;
    ans = max(ans, dp(idx+1, sp+1, ip) + sp1cnt + ip0cnt);
    return memo[idx][{sp, ip}] = ans;
}

void solve() {
    cin >> n >> m;
    r = vi(n); afr(r) cin >> u;
    int j = 0;
    z = vi(m); frn(i, n) if(r[i] == 0) z[j++] = i;
    z.pb(n);
    memo = vector<map<pii, int>>(m);
    checks = vector<pair<multiost, multiost>>(m);
    frn(i, m) {
        for(int j=z[i]+1; j<z[i+1]; j++) {
            if(r[j] < 0) checks[i].f.insert(-r[j]);
            else checks[i].s.insert(r[j]);
        }
        // cout << i << endl;
        // checks[i].f.printo();
        // checks[i].s.printo();
    }
    cout << dp(0, 0, 0) << endl;
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

