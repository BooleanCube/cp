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
#define endl "\n" // remove when debugging

template <class T>
struct segtree {
    using vt = vector<T>;
    const int n; const static T def = 0;
    vt tree, lazy;
    vector<pii> rng;
    segtree(int N) : n(N) {
        tree = vt(n<<1, (T)def), lazy = vt(n<<1, (T)def), rng = vector<pii>(n<<1);
        rng[0] = _construct(1);
    }
    pii _construct(int idx) {
        if(idx >= n) return rng[idx] = {idx-n, idx-n};
        int ch = idx << 1; // left child
        pii lh = _construct(ch);
        pii rh = _construct(ch+1);
        return rng[idx] = {lh.f, rh.s};
    }
    T value(int idx, T val) { return val * (rng[idx].s - rng[idx].f + 1); }
    void update(int l, int r, T val) { _incUpdate(l+n, r+n, val); }
    void _incUpdate(int l, int r, T val) {
        for(;l<r; l>>=1,r>>=1) {
            if(l & 1) { _updateLazy(l, val); lazy[l++] = op(lazy[l], val); }
            if(l == r) break;
            if(!(r & 1)) { _updateLazy(r, val); lazy[r--] = op(lazy[r], val); }
        }
        _updateLazy(l, val); lazy[l] = op(lazy[l], val);
    }
    void _updateLazy(int idx, T val) { for(val=value(idx, val); idx; idx>>=1) tree[idx] = op(tree[idx], val); }
    T query(int l, int r) { return _queryTree(l+n, r+n); }
    T _queryTree(int l, int r, T t = def) {
        for(;l<r; l>>=1,r>>=1) {
            if(l & 1) { t = mop({t, value(l, _climbLazy(l)), tree[l]}); l++; }
            if(l == r) break;
            if(!(r & 1)) { t = mop({t, value(r, _climbLazy(r)), tree[r]}); r--; }
        }
        return mop({value(l, _climbLazy(l)), tree[l], t});
    }
    T _climbLazy(int idx, T cnt = def) { for(idx>>=1; idx; idx>>=1) cnt = op(cnt, lazy[idx]); return cnt; }
    T op(T a, T b) { return max(a, b); }
    T mop(vt v, T t = def) { for(T x : v) t = op(t, x); return t; }
};

const int MAXN = 4e5+1;

segtree<ll> seg(MAXN);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    set<int> ends;
    map<int, int> cc; int id = 1;
    vector<array<ll, 3>> p(n);
    for(int i=0; i<n; i++) {
        cin >> p[i][1] >> p[i][0] >> p[i][2];
        ends.insert(p[i][0]); ends.insert(p[i][1]);
    }
    for(int end : ends) cc[end] = id++;
    sort(p.begin(), p.end());
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll sp = cc[p[i][1]], ep = cc[p[i][0]], x = p[i][2];
        ll mp = seg.query(0, sp-1);
        ll val = mp + x;
        seg.update(ep, ep, val);
        ans = max(ans, val);
    }
    cout << ans << endl;
    return 0;
}
