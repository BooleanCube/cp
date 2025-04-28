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


int n;
vector<vi> votes;
vector<int> memo;

int dp(int idx) {
    if(idx == n) return 0;
    if(memo[idx] != -1) return memo[idx];
    int ans = 0;
    int fb = (votes[0][idx] + votes[1][idx] + votes[1][idx+1]) > 1;
    int sb = (votes[1][idx+1] + votes[1][idx+2] + votes[0][idx+2]) > 1;
    int ft = (votes[0][idx] + votes[1][idx] + votes[0][idx+1]) > 1;
    int st = (votes[0][idx+1] + votes[1][idx+2] + votes[0][idx+2]) > 1;
    int tt = (votes[0][idx] + votes[0][idx+1] + votes[0][idx+2]) > 1;
    int bb = (votes[1][idx] + votes[1][idx+1] + votes[1][idx+2]) > 1;

    int sst = (votes[0][idx+4] + votes[1][idx+5] + votes[0][idx+5]) > 1;
    int ssb = (votes[1][idx+4] + votes[1][idx+5] + votes[0][idx+5]) > 1;
    int ftt = (votes[0][idx+1] + votes[0][idx+2] + votes[0][idx+3]) > 1;
    int fftt = (votes[0][idx+2] + votes[0][idx+3] + votes[0][idx+4]) > 1;
    int fbb = (votes[1][idx+1] + votes[1][idx+2] + votes[1][idx+3]) > 1;
    int ffbb = (votes[1][idx+2] + votes[1][idx+3] + votes[1][idx+4]) > 1;
    // cout << idx sp fb sp st sp ft sp sb << endl;
    ans = max(ans, dp(idx+3) + fb + st);
    ans = max(ans, dp(idx+3) + ft + sb);
    ans = max(ans, dp(idx+3) + tt + bb);
    if(idx + 6 <= n) {
        ans = max(ans, dp(idx+6) + fb + ftt + ffbb + sst);
        ans = max(ans, dp(idx+6) + ft + fbb + fftt + ssb);
    }
    return memo[idx] = ans;
}

void solve() {
    cin >> n;
    string a, b; cin >> a >> b;
    votes = vector<vi>(2, vi(n));
    for(int i=0; i<n; i++) {
        votes[0][i] = (a[i] == 'A');
        votes[1][i] = (b[i] == 'A');
    }
    memo = vector<int>(n, -1);

    cout << dp(0) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;
    cfr(t, 1, tc) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

