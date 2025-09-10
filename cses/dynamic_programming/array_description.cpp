#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9+7;

int main() {
    int n, m; cin >> n >> m;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    vector<vector<ll>> dp(n, vector<ll>(m+1));
    ll ans = 1, works = 1;
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) {
            if(i == 0) {
                for(int j=1; j<=m; j++)
                    dp[i][j]++;
            } else {
                int prev = nums[i-1];
                if(prev) {
                    for(int j=max(1,prev-1); j<=min(m,prev+1); j++)
                        dp[i][j]++;
                } else {
                    for(int j=1; j<=m; j++) {
                        for(int k=max(1,j-1); k<=min(m,j+1); k++) {
                            dp[i][j] += dp[i-1][k];
                            dp[i][j] %= MOD;
                        }
                    }
                }
            }
        } else if(i > 0 && nums[i-1] == 0) {
            ll sum = 0;
            for(int j=max(1,nums[i]-1); j<=min(m,nums[i]+1); j++) {
                sum += dp[i-1][j];
                sum %= MOD;
            }
            ans *= sum;
            ans %= MOD;
        } else if(i > 0 && nums[i-1] && abs(nums[i]-nums[i-1])>1) {
            works = 0;
        } 
    }
    if(nums[n-1] == 0) {
        ll sum = 0;
        for(int j=1; j<=m; j++) {
            sum += dp[n-1][j];
            sum %= MOD;
        }
        ans *= sum;
        ans %= MOD;
    }
    cout << (works ? ans : 0) << endl;
    return 0;
}