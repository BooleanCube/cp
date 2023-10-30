#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    int start = 0;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for(int i=0; i<n; i++) {
        if(i+1<n) dp[i+1] = min(dp[i+1], dp[i]+abs(h[i]-h[i+1]));
        if(i+2<n) dp[i+2] = min(dp[i+2], dp[i]+abs(h[i]-h[i+2]));
    }
    cout << dp[n-1] << endl;
    return 0;
}