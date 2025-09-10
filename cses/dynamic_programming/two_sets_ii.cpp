#include <bits/stdc++.h>
using namespace std;

#define sp <<" "<<
#define ll long long

const ll MOD = 1e9+7;

ll fastexp(ll base, ll expo) {
    if(expo == 0) return 1;
    ll half = fastexp(base, expo/2);
    ll ans = half*half; ans%=MOD;
    if(expo&1) (ans *= base) %= MOD;
    return ans;
}

int main() {
    int n, sum = 0; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        nums[i] = i+1;
        sum += nums[i];
    }
    if(sum & 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> DP(sum+1, 0);
    for(int num : nums) {
        for(int j=sum; j>=0; j--) {
            if(DP[j]) {
                DP[j+num] += DP[j];
                DP[j+num] %= MOD;
            }
        }
        DP[num]++;
        DP[num] %= MOD;
    }
    cout << (DP[sum/2]*fastexp(2, MOD-2))%MOD << endl;
    return 0;
}