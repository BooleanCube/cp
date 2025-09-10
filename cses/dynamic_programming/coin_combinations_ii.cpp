#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define ll long long
#define int ll
#define vi vector<int>
const int md = 1000000007;

signed main() {
    int n,x; cin >> n >> x;
    vi coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    sort(begin(coins), end(coins));
    vi dp(1000001, 0);
    dp[0] = 1;
    for(int c : coins) {
        for(int i=0; i<=x; i++) {
            int val = i+c;
            if(val>x) continue;
            dp[val] += dp[i];
            dp[val] %= md;
        }
    }
    cout << dp[x] << endl;
    return 0;
}
