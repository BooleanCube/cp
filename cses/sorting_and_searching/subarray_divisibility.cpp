#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n; cin >> n;
    vector<int> nums(n), fq(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        if(nums[i] < 0) nums[i] = n-abs(nums[i])%n;
        else nums[i] %= n;
    }
    vector<int> ps; ps.push_back(0);
    for(int i=0; i<n; i++) ps.push_back((ps[i]+nums[i])%n);
    int ans = 0;
    for(int i=0; i<=n; i++) ans += fq[ps[i]]++;
    cout << ans << endl;
    return 0;
}
