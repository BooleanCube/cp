#include <bits/stdc++.h>
using namespace std;

int kp(int n, int p, int pages[], int prices[]) {
    vector<vector<int>> dp(n+1, vector<int>(p+1));
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<p+1; j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(prices[i-1] <= j) dp[i][j] = max(dp[i-1][j], pages[i-1]+dp[i-1][j-prices[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][p];
}

int main() {
    int n, p; cin >> n >> p;
    int pages[n];
    int prices[n];
    for(int i=0; i<n; i++) cin >> prices[i];
    for(int i=0; i<n; i++) cin >> pages[i];
    cout << kp(n, p, pages, prices) << "\n";
    return 0;
}