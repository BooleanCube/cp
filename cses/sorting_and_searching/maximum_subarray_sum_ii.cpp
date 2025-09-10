#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define ll long long

int main() {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> nums(n+1);
    for(int i=1; i<=n; i++) {
        cin >> nums[i];
        nums[i] += nums[i-1];
    }
    multiset<ll> starts;
    ll ans = LLONG_MIN;
    for(int i=0; i<=n; i++) {
        if(i < a) continue;
        starts.insert(nums[i-a]);
        if(i >= b+1) {
            auto it = starts.find(nums[i-b-1]);
            starts.erase(it);
        }
        ans = max(ans, nums[i]-(*starts.begin()));
    }
    cout << ans << endl;
}