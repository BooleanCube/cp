#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int __int128

void print(int x) {
    if(x == 0) {
        cout << "0" << endl;
        return;
    }
    vector<ll> res;
    while(x) {
        res.push_back((ll)(x%10));
        x /= 10;
    }
    reverse(res.begin(), res.end());
    ll n = res.size();
    for(ll i=0; i<n; i++) cout << res[i];
    cout << endl;
}

signed main() {
    ll t, k; cin >> t >> k;
    int n = (int)t;
    vector<ll> a(k);
    for(ll i=0; i<k; ++i) cin >> a[i];
    int ans = 0;
    for(ll mask=1; mask<(1<<k); ++mask) {
        int d = 1, c = 0;
        for(ll i=0; i<k; ++i) {
            if(mask & (1 << i)) {
                d *= a[i];
                if(d > n) {
                    d = n+1;
                    break;
                }
                c++;
            }
        }
        if(c&1) ans += n/d;
        else ans -= n/d;
    }
    print(ans);
    return 0;
}
