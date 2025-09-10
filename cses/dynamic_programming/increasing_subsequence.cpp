#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    vector<int> lis;
    lis.push_back(nums[0]);
    for(int i=1; i<n; i++) {
        if(nums[i] > lis[sz(lis)-1]) lis.push_back(nums[i]);
        else {
            auto it = lower_bound(all(lis), nums[i]);
            int idx = it - lis.begin();
            lis[idx] = nums[i];
        }
    }
    cout << sz(lis) << endl;
    return 0;
}