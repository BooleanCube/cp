#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    int mx = 0;
    for(int i=0; i<n; i++) { cin >> nums[i]; mx = max(mx, nums[i]); }
    ll lo = mx, hi = 1e15;
    while(lo < hi) {
        ll mid = lo + (hi-lo)/2;
        ll cnt = 1, csum = 0;
        for(int i=0; i<n; i++) {
            csum += nums[i];
            if(csum > mid) {
                cnt++;
                csum = nums[i];
            }
        }
        if(cnt <= k) hi = mid;
        else lo = mid+1;
    }
    cout << lo << endl;
    return 0;
}
