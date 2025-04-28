#include <bits/stdc++.h>
using namespace std;


/* TYPES  */
#define ll unsigned long long
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
const ll MAXN = 1e5+5;
const ll MOD = 1e9+7;
const ll HMOD = 998244353;
const ll INF = 1e9;
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

/* FUNCTIONS */
#define sz(a) ((int)a.size())
#define all(a) (a).begin(), (a).end()
#define fr(i,s,e) for(int i=(s);i<(e);i++)
#define frn(i,n) fr(i,0,(n))
#define cfr(i,s,e) for(int i=(s);i<=(e);i++)
#define rfr(i,e,s) for(int i=(e)-1;i>=(s);i--)
#define afr(a) for(auto u:a)
#define pb push_back
#define eb emplace_back

/* DEBUGGING && PRINTING */
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f sp u.s<<endl;}

ll pow(int n) {
    int a = 1;
    while(n--) a *= 2;
    return a;
}

void solve() {
    ll b, c, d; cin >> b >> c >> d;
    ll ob = b, oc = c, od = d;
    ll a = 0;
    for(ll i=0; i<61; i++) {
        ll w = (d & pow(i)) > 0;
        ll p2 = pow(i);
        ll bb = (b & pow(i)) > 0, cb = (c & pow(i)) > 0;
        // cout << i sp w sp bb sp cb << endl;
        if(w) {
            if(!bb && cb && p2 < b) {
                ll j = i+1;
                while(pow(j) <= b && (b & pow(j)) == 0) {
                    b ^= pow(j);
                    j++;
                }
                b ^= pow(j);
                if(d & pow(j)) {
                    cout << -1 << endl;
                    return;
                }
            }
            else a |= (bb && cb ? 0 : pow(i));
        }
        else if(bb && !cb && i > 0) {
            ll pi = i - 1;
            ll pbb = (b & pow(pi)) > 0, pcb = (c & pow(pi)) > 0;
            // cout << i sp pi sp pbb sp pcb << endl;
            if(!pbb && pcb) {
                if(a & pow(pi)) a ^= pow(pi);
            } else {
                cout << -1 << endl;
                return;
            }
        }
        else if(bb && cb) a |= pow(i);
        // cout << a << endl;
    }
    cout << a << endl;
    // cout << (a | ob) sp (a & oc) sp ((a | ob) - (a & oc)) << endl;
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

