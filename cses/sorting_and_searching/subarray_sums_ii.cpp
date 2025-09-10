#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> psum(1);
    psum[0] = 0;
    for(int i=0; i<n; i++) {
        ll a; cin >> a;
        psum.emplace_back(psum[i]+a);
    }
    map<ll, ll> fq;
    for(ll ps : psum) {
        if(fq.count(ps)) fq[ps]++;
        else fq[ps] = 1;
    }
    ll ans = 0;
    for(int i=0; i<n; i++) {
        fq[psum[i]]--;
        if(fq.count(psum[i]+x)) ans += fq[psum[i]+x];
    }
    cout << ans << endl;
    return 0;
}