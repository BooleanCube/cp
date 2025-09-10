#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
const ll md = 1000000007;

signed main() {
    int n,k; cin >> n >> k;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    vector<int> dp(1000000, 0);
    dp[0] = 0;
    for(int i : coins) dp[i] = 1;
    for(int i=1; i<=k; i++) {
        for(int j : coins) {
            int v = i-j;
            if(v<0) continue;
            dp[i] += dp[v];
            dp[i] %= md;
        }
    }
    cout << dp[k] << endl;
    return 0;
}
