#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
#define f first
#define s second

const int MAXD = 1e16;

signed main() {
    int n, m, q; cin >> n >> m >> q;
    vvp graph(n+1);
    vvi dp(n+1, vi(n+1, MAXD));
    for(int i=0; i<m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
        dp[a][b] = dp[b][a] = min(dp[a][b], w);
    }
    for(int i=0; i<=n; i++) dp[i][i] = 0;
    for(int m=1; m<=n; m++) {
        for(int s=1; s<=n; s++) {
            for(int e=1; e<=n; e++) {
                dp[s][e] = dp[e][s] = min(dp[s][e], dp[s][m] + dp[m][e]);
            }
        }
    }
    for(int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        cout << (dp[a][b] < MAXD ? dp[a][b] : -1) << endl;
    }
    return 0;
}
