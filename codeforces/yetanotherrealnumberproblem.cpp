#include <bits/stdc++.h>
using namespace std;


/* TYPES  */
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pii>
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

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int ll


vi seg;

void update(int idx, int val) {
    while(idx) {
        seg[idx] += val + MOD;
        seg[idx] %= MOD;
        idx >>= 1;
    }
}

int query(int l, int r, int t) {
    if(l == r) return (seg[l] + t) % MOD;
    if(l & 1) return query(l+1, r, (t+seg[l]) % MOD);
    if(!(r & 1)) return query(l, r-1, (t+seg[r]) % MOD);
    return query(l >> 1, r >> 1, t);
}

pair<int, int> div2(int x) {
    int cnt = 0;
    while(!(x & 1)) {
        cnt++;
        x >>= 1;
    }
    return {x, cnt};
}

// a * 2^x < b * 2^y
int cmp(int a, int x, int b, int y) {
    // cuz a/b is 1e9 max
    if(y - x >= 32) return 1;
    // cout << ((ld)a / (ld)b) sp powl(2, y - x) << endl;
    return ((ld)a / (ld)b) < powl(2, y - x);
}

int mpow(int b, int e) {
    if(e == 0) return 1;
    int x = mpow(b, e >> 1);
    x *= x; x %= MOD;
    if(e & 1) return (b * x) % MOD;
    return x;
}

void solve() {
    int n; cin >> n;
    vi a(n); afr(a) cin >> u;
    vi p(n), b(n);
    frn(i, n) {
        pii d = div2(a[i]);
        b[i] = d.f;
    }

    seg = vi(2*n);

    vi ans(n); ans[0] = a[0]; p[0] = div2(a[0]).s;
    set<pii> pts; pts.insert({b[0], 0});
    fr(i, 1, n) {
        int flag = 1;
        while(flag) {
            flag = 0;
            set<pii> rm;
            for(auto [pv, pi] : pts) {
                // cout << pv sp p[pi] sp a[i] sp (p[i]+p[pi]) sp cmp(pv, p[pi], a[i], p[i]+p[pi]) << endl;
                if(cmp(pv, p[pi], a[i], p[pi])) {
                    flag = 1;
                    p[i] += p[pi];
                    p[pi] = 0;
                    rm.insert({pv, pi});
                    update(pi + n, -seg[pi+n] + pv);
                }
            }
            for(auto pr : rm) pts.erase(pr);
        }

        if(pts.size() > 0) {
            int mxv = 0, mxi = 0, smp = 0;
            // for(auto [pv, pi] : pts) cout << pv sp pi sp p[pi] << endl;
            for(auto [pv, pi] : pts) {
                if(cmp(mxv, mxi, pv, pi)) {
                    mxv = pv;
                    mxi = pi;
                }
                smp += p[pi];
                // cout << pv sp p[pi] sp a[i] sp (p[i]+p[pi]) sp cmp(pv, p[pi], a[i], p[i]+p[pi]) << endl;
            }
            if(cmp(mxv, p[mxi], a[i], p[i] + smp)) {
                p[i] += smp;
                for(auto [pv, pi] : pts) {
                    p[pi] = 0;
                    update(pi + n, -seg[pi+n] + pv);
                }
                pts.clear();
            }
        } 

        update(i + n, (a[i] * mpow(2, p[i])) % MOD);
        ans[i] = query(n, i+n, 0);

        p[i] += div2(a[i]).s;
        if(p[i]) pts.insert({b[i], i});
    }

    printv(ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;
    cfr(t, 1, tc) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

