#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n), ans(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    multiset<array<int, 2>, greater<array<int, 2>>> ops;
    for(int i=n-1; i>=0; i--) {
        for(auto it = ops.begin(); it!=ops.end();) {
            auto [x, idx] = *it;
            if(nums[i] < x) {
                ans[idx] = i+1;
                auto next = (++it)--;
                ops.erase(it);
                it = next;
            } else break;
        }
        ops.insert({nums[i], i});
    }
    ans[0] = 0;
    for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
