#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define vi vector<int>

const int MAXN = 1e6+5;

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


const int primeCnt = 78499;

bitset<1000006> p;
int dp[MAXN], primes[primeCnt];

void sieve() {
    p = ~p;
    p[0] = p[1] = 0;
    for(int i=2; i*i<MAXN; i++)
        if(p[i])
            for(int j=i*i; j<MAXN; j+=i)
                p[j] = 0;
    int pidx = 0;
    for(int i=2; i<MAXN; i++)
        if(p[i])
            primes[pidx++] = i;
}

void solve() {
    sieve();
    int n; scanf("%d", &n);
    ll ans = 0;
    frn(i, n) {
        int x; scanf("%d", &x);
        vi pf;
        for(int pn : primes) {
            if(x == 1) break;
            if(x % pn) continue;
            pf.pb(pn);
            while(x % pn == 0) x /= pn;
        }

        int cnt = sz(pf);
        for(int mask=0; mask<(1<<cnt); mask++) {
            int prod = 1;
            frn(j, cnt)
                if(mask & (1 << j))
                    prod *= pf[j];
            int bits = __builtin_popcount(mask);
            ans += ((bits & 1) ? -dp[prod] : dp[prod]);
            dp[prod]++;
        }
    }
    cout << ans << endl;
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    int tc = 1;
    // cin >> tc;
    cfr(t, 1, tc) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

