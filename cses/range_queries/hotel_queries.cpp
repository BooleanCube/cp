// Source: https://usaco.guide/general/io

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
    const int n; constexpr static T def = 0;
    vt tree, lazy;
    vector<pii> rng;
    segtree(int N) : n(N) {
        tree = vt(n<<2), lazy = vt(n<<2), rng = vector<pii>(n<<2);
        rng[0] = _construct(1);
    }
    pii _construct(int idx) {
        if(idx >= n) return rng[idx] = {idx-n, idx-n};
        return rng[idx] = {_construct(idx << 1).f, _construct((idx << 1)+1).s};
    }
    T value(int idx, T val) { return val * (rng[idx].s - rng[idx].f + 1); }
    void update(int l, int r, T val) { _setUpdate(l+n, r+n, val); }
    void _setUpdate(int l, int r, T val) {
        for(;l<r; l>>=1,r>>=1) {
            if(l & 1) { _updateLazy(l, val); lazy[l++] = val; }
            if(l == r) break;
            if(!(r & 1)) { _updateLazy(r, val); lazy[r--] = val; }
        }
        _updateLazy(l, val); lazy[l] = val;
    }
    void _updateLazy(int idx, T val) { for(val=value(idx, val); idx; idx>>=1) tree[idx] = op(tree[idx*2], tree[idx*2+1], val); }
    T query(int l, int r) { return _queryTree(l+n, r+n); }
    T _queryTree(int l, int r, T t = def) {
        for(;l<r; l>>=1,r>>=1) {
            if(l & 1) { t = op(t, value(l, _climbLazy(l)), tree[l]); l++; }
            if(l == r) break;
            if(!(r & 1)) { t = op(t, value(r, _climbLazy(r)), tree[r]); r--; }
        }
        return op(value(l, _climbLazy(l)), tree[l], t);
    }
    T _climbLazy(int idx, T cnt = def) { for(idx>>=1; idx; idx>>=1) cnt = op(cnt, lazy[idx]); return cnt; }
    T op(T a, T b) { return max(a, b); }
    T op(T a, T b, T c) { return op(a, op(b, c)); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int n, m; cin >> n >> m;
	vi rooms(n), groups(m);
	for(auto &u : rooms) cin >> u;
	for(auto &u : groups) cin >> u;

	segtree<ll> seg(n);
	for(int i=0; i<n; i++) seg.update(i, i, rooms[i]);

	vi ans(m);
	for(int i=0; i<m; i++) {
		int group = groups[i];
        int lo = 0, hi = n-1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int val = seg.query(0, mid);
            if(val >= group) hi = mid;
            else lo = mid+1;
        }
        int val = seg.query(0, lo);
        if(val < group) { ans[i] = 0; continue; }
		ans[i] = lo + 1;
		seg.update(lo, lo, val-group);
	}

	for(int i=0; i<m; i++) cout << ans[i] << " \n"[i==m-1];

    return 0;
}