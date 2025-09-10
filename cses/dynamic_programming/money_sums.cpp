#include <bits/stdc++.h>
using namespace std;

#define sp <<" "<<

int main() {
    int n, sum = 0; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    vector<int> DP(sum+1);
    for(int num : nums) {
        for(int j=sum; j>=0; j--) {
            if(DP[j]) DP[j+num] = 1;
        }
        DP[num] = 1;
    }
    vector<int> ans(0);
    for(int i=0; i<=sum; i++) {
        if(DP[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " \n"[i==ans.size()-1];
    return 0;
}