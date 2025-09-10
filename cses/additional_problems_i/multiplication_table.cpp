#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    ll median = n*n/2+1;
    ll lo = 1, hi = 1e13;
    while(lo < hi) {
        ll mid = lo + ((hi-lo) >> 1);
        ll cnt = 0;
        for(int i=1; i<=n; i++) cnt += min(n, mid/i);
        if(cnt < median) lo = mid+1;
        else hi = mid-1;
    }
    ll cnt = 0;
    for(int i=1; i<=n; i++) cnt += min(n, hi/i);
    cout << (cnt >= median ? hi : hi+1) << endl;
    return 0;
}
