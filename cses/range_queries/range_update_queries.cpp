#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define f first
#define s second
#define sp <<" "<<
#define endl "\n" // remove when debugging


template <class T>
struct segtree {
    using vt = vector<T>;
    const int n;
    constexpr static T def = 0; constexpr static T inf = 1e16;
    vt tree, lazy;
    vector<pii> rng;
    segtree(int N) : n(N) {
        tree = vt((n<<1), def), lazy = vt((n<<1), def);
    }
    T value(T val) { return val == inf ? 0 : val; }
    void increment(int l, int r, T val) {
        for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
            if(l & 1) { tree[l] += val; _updateLazy(l); lazy[l++] = val+value(lazy[l]); }
            if(l == r) break;
            if(!(r & 1)) { tree[r] += val; _updateLazy(r); lazy[r--] = val+value(lazy[r]); }
        }
        tree[l] += val; _updateLazy(l); lazy[l] += val;
    }
    void _updateLazy(int idx) { for(idx>>=1; idx; idx>>=1) tree[idx] = op(tree[idx*2], tree[idx*2+1]); }
    T query(int l, int r, T t = inf) {
        for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
            if(l & 1) { t = op(t, tree[l] + _climbLazy(l)); l++; }
            if(l == r) break;
            if(!(r & 1)) { t = op(t, tree[r] + _climbLazy(r)); r--; }
        }
        return op(t, tree[l] + _climbLazy(l));
    }
    T _climbLazy(int idx, T cnt = def) { for(idx>>=1; idx; idx>>=1) cnt += lazy[idx]; return cnt; }
    T op(T a, T b) { return min(a, b); }
    T op(T a, T b, T c) { return op(a, op(b, c)); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q; cin >> n >> q;
    vi a(n); for(auto &u : a) cin >> u;
    segtree<ll> seg(n);
    for(int i=0; i<n; i++) seg.increment(i, i, a[i]);
    for(int i=0; i<q; i++) {
        int op; cin >> op;
        if(op == 1) {
            ll l, r, u; cin >> l >> r >> u;
            seg.increment(l-1, r-1, u);
        } else {
            ll k; cin >> k;
            cout << seg.query(k-1, k-1) << endl;
        }
    }

    return 0;
}