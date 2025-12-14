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


template <class T>
struct segtree {
    using vt = vector<T>;
    const int n; constexpr static T def = 0;
    vt tree, lazy;
    vector<pii> rng;
    segtree(int N) : n(N) {
        tree = vt(n<<1), lazy = vt(n<<1), rng = vector<pii>(n<<1);
        rng[0] = _construct(1);
    }
    pii _construct(int idx) {
        if(idx >= n) return rng[idx] = {idx-n, idx-n};
        return rng[idx] = {_construct(idx << 1).f, _construct((idx << 1)+1).s};
    }
    T value(int idx, T val) { return val * (rng[idx].s - rng[idx].f + 1) % MOD; }
    void update(int l, int r, T val) { _incUpdate(l+n, r+n, val); }
    void _incUpdate(int l, int r, T val) {
        for(;l<r; l>>=1,r>>=1) {
            if(l & 1) { _updateLazy(l, val); lazy[l++] = op(lazy[l], val) % MOD; }
            if(l == r) break;
            if(!(r & 1)) { _updateLazy(r, val); lazy[r--] = op(lazy[r], val) % MOD; }
        }
        _updateLazy(l, val); lazy[l] = op(lazy[l], val) % MOD;
    }
    void _updateLazy(int idx, T val) { for(val=value(idx, val); idx; idx>>=1) tree[idx] = op(tree[idx], val) % MOD; }
    T query(int l, int r) { return _queryTree(l+n, r+n); }
    T _queryTree(int l, int r, T t = def) {
        for(;l<r; l>>=1,r>>=1) {
            if(l & 1) { t = op(t, value(l, _climbLazy(l)), tree[l]) % MOD; l++; }
            if(l == r) break;
            if(!(r & 1)) { t = op(t, value(r, _climbLazy(r)), tree[r]) % MOD; r--; }
        }
        return op(value(l, _climbLazy(l)), tree[l], t) % MOD;
    }
    T _climbLazy(int idx, T cnt = def) { for(idx>>=1; idx; idx>>=1) cnt = op(cnt, lazy[idx]) % MOD; return cnt; }
    T op(T a, T b) { return (a + b) % MOD; }
    T op(T a, T b, T c) { return op(a, op(b, c)) % MOD; }
};

void solve() {
  int n; cin >> n;
  vi x(n); afr(x) cin >> u;
  vi a(n); frn(i, n) a[i] = x[i];
  sort(all(a));
  int g = 0; mii cc, rcc;
  afr(a) cc[u] = g, rcc[g] = u, g++;
  afr(x) u = cc[u];
  segtree<int> tree(g+1);
  frn(i, n) {
    int val = tree.query(0, x[i]-1);
    // cout << i sp x[i] sp val << endl;
    tree.update(x[i], x[i], (val + 1) % MOD);
  }
  cout << tree.query(0, g) % MOD << endl;
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

