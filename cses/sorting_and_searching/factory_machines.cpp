#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long

int main() {
    ll n, t; cin >> n >> t;
    vector<ll> k(n);
    for(int i=0; i<n; i++) cin >> k[i];
    sort(k.begin(), k.end());
    ll lo = 0, hi = 5e18;
    while(lo < hi) {
        ll mid = lo + ((hi-lo) >> 1);
        ll cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += mid/k[i];
            if(cnt > t) break;
        }
        if(cnt < t) lo = mid+1;
        else hi = mid;
    }
    
    cout << hi << endl;
    return 0;
}
