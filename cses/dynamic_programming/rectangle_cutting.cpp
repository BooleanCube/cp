#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int dp(int a, int b) {
    if(a == b) return memo[a][b] = 0;
    if(memo[a][b] > -1) return memo[a][b];
    if(a == 1) return memo[a][b] = b-1;
    if(b == 1) return memo[a][b] = a-1;
    int ans = 1e9;
    for(int i=1; i<a/2+1; i++)
        ans = min(ans, dp(i, b)+dp(a-i, b)+1);
    for(int i=1; i<b/2+1; i++)
        ans = min(ans, dp(a, i)+dp(a, b-i)+1);
    return memo[a][b] = ans;
}

int main() {
    int a, b; cin >> a >> b;
    memo = vector<vector<int>>(a+1, vector<int>(b+1, -1));
    cout << dp(a, b) << endl;
    return 0;
}