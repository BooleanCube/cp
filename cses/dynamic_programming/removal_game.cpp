#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define sp <<" "<<

int n;
vector<int> nums;
vector<vector<int>> DP;

int dp(int l, int r, int cnt) {
    if(cnt == n) return 0;
    if(DP[l][r] != -1) return DP[l][r];
    int takeL = dp(l+1, r, cnt+1)+(cnt&1 ? -1 : 1)*nums[l];
    int takeR = dp(l, r-1, cnt+1)+(cnt&1 ? -1 : 1)*nums[r];
    int take = cnt&1? min(takeL, takeR) : max(takeL, takeR);
    return DP[l][r] = take;
}

signed main() {
    cin >> n; int sum = 0;
    nums = vector<int>(n), DP = vector<vector<int>>(n, vector<int>(n, -1));
    for(int i=0; i<n; i++) { cin >> nums[i]; sum += nums[i]; }
    cout << (int)(sum/2.0 + dp(0, n-1, 0)/2.0) << endl;
    return 0;
}