#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
int main (int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> dp(1000001, 1000001);
    for(int i=0; i<10; i++) dp[i] = 1;
    for(int i=10; i<=n; i++) {
        int current = i;
        while(current > 0) {
            int digit = current%10;
            dp[i] = min(dp[i], dp[i-digit]+1);
            current /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}