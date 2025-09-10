#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6+5;
const int MOD = 1e9+7;

int main() {
    vector<array<ll, 2>> DP(N);
    DP[1][0] = 1; DP[1][1] = 1;
    for(int i=2; i<N; i++) {
        DP[i][0] = (DP[i-1][0]*2+DP[i-1][1])%MOD;
        DP[i][1] = (DP[i-1][1]*4+DP[i-1][0])%MOD;
    }
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cout << (DP[n][0] + DP[n][1])%MOD << endl;
    }
    return 0;
}