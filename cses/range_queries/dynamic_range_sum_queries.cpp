#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
 
vector<int> tree;
 
void update(int idx, int val) {
    int org = tree[idx];
    while(idx > 0) {
        tree[idx] -= org;
        tree[idx] += val;
        idx >>= 1;
    }
}
 
int query(int l, int r, int s) {
    if(l == r) return s+tree[l];
    if(l % 2) return query(l+1, r, s+tree[l]);
    if((r % 2) == 0) return query(l, r-1, s+tree[r]);
    return query((l>>1), (r>>1), s);
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, q; cin >> n >> q;
    tree = vector<int>(2*n);
    for(int i=0; i<n; i++) {
        int val; cin >> val;
        update(n+i, val);
    }
    for(int i=0; i<q; i++) {
        int op; cin >> op;
        if(op == 1) {
            int idx, val; cin >> idx >> val;
            update(n+idx-1, val);
        }
        else {
            int l, r; cin >> l >> r;
            int ans = query(n+l-1, n+r-1, 0);
            cout << ans << endl;
        }
    }
    return 0;
}
