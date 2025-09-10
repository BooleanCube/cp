#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)

vector<int> d, pref;

// [lb, ub)
ll split(int lb, int ub) {
    if(ub-lb <= 1) return 0;
    ll tsum = pref[ub] - pref[lb];
    ll prev = 1e12, mp = 0;
    for(int m=lb+1; m<=ub; m++) {
        ll fh = pref[m] - pref[lb];
        ll sh = tsum - fh;
        if(abs(fh-sh) < prev) {
            prev = abs(fh-sh);
            mp = m;
        } else break;
    }
    return tsum + split(lb, mp) + split(mp, ub);
}

int main() {
    int x, n; cin >> x >> n;
    d = vector<int>(n);
    pref = vector<int>(n+1);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        cin >> d[i];
        pref[i+1] = pref[i] + d[i];
        pq.push(d[i]);
    }
    sort(all(d));
    // ll ans = split(0, n);
    ll ans = 0;
    while(pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    cout << ans << endl;
    return 0;
}
