#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sp <<" "<<

int comb2(int x) {
    return x * (x + 1) / 2;
}

signed main() {
    int n; cin >> n;
    vector<int> a(n); for(auto &u : a) cin >> u;

    map<int, int> inds;
    int l = 0, ans = 0;
    for(int r=0; r<n; r++) {
        if(inds.count(a[r])) {
            int nl = inds[a[r]] + 1;
            ans += comb2(r - l) - comb2(r - nl);
            for(int i=l; i<nl; i++) inds.erase(a[i]);
            l = nl;
        }
        inds[a[r]] = r;
    }
    ans += comb2(n - l);

    cout << ans << endl;

    return 0;
}