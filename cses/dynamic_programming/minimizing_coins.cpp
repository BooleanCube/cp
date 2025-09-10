#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    vector<int> dp(1000001, 10000000);
    dp[0] = 0;
    for(int i : coins) dp[i] = 1;
    for(int i=1; i<=k; i++) {
        for(int j : coins) {
            int v = i-j;
            if(v<0) continue;
            dp[i] = min(dp[i], dp[j]+dp[v]);
        }
    }
    if(dp[k] == 1e7) cout << -1 << endl;
    else cout << dp[k] << endl;
    return 0;
}
