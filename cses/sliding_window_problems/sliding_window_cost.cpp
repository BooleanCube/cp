#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define int ll
 
struct ost_multiset {
    typedef pair<int, unsigned> pii;
    typedef tree<
        pii,
        null_type,
        less<pii>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ost;
 
    ost s;
    unsigned cnt = 0;
 
    ost_multiset() = default;
    ost_multiset(initializer_list<int> l) {
        for (int x : l) insert(x);
    }
    void insert(int x) { s.insert({x, cnt++}); }
    ost::iterator find_by_order(int k) { return s.find_by_order(k); }
    void erase(int x) {
        auto it = s.lower_bound({x, 0});
        erase(it); // erases only 1 element
        // while(it != s.end() && it->first == x) erase(it++);
    }
    void erase(ost::iterator it) { s.erase(it); }
    size_t size() const { return s.size(); }
};

template <class T>
struct segtree {
    using vt = vector<T>;
    const int n; constexpr static T def = {0, 0};
    vt tree, lazy;
    vector<pii> rng;
    segtree(int N) : n(N) {
        tree = vt(n<<1, (T)def), lazy = vt(n<<1, (T)def), rng = vector<pii>(n<<1);
        rng[0] = _construct(1);
    }
    pii _construct(int idx) {
        if(idx >= n) return rng[idx] = {idx-n, idx-n};
        int ch = idx << 1; // left child
        pii lh = _construct(ch), rh = _construct(ch+1);
        return rng[idx] = {lh.f, rh.s};
    }
    T value(int idx, T val) { return {val.f*(rng[idx].s-rng[idx].f+1),val.s*(rng[idx].s-rng[idx].f+1)}; }
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
            if(l & 1) { t = op(t, value(l, _climbLazy(l)), tree[l]); l++; }
            if(l == r) break;
            if(!(r & 1)) { t = op(t, value(r, _climbLazy(r)), tree[r]); r--; }
        }
        return op(value(l, _climbLazy(l)), tree[l], t);
    }
    T _climbLazy(int idx, T cnt = def) { for(idx>>=1; idx; idx>>=1) cnt = op(cnt, lazy[idx]); return cnt; }
    T op(T a, T b) { return {a.f+b.f, a.s+b.s}; }
    T op(T a, T b, T c) { return op(a, op(b, c)); }
};
 
const int MAXN = 2e5+2;
 
ost_multiset ost;
segtree<pll> st(MAXN);
int n, k, id;
vector<int> ans, ccr(MAXN);
map<int, int> cc;
 
int cost() {
    int median = ost.find_by_order((k-1)>>1)->first;
    pll lc = st.query(0, median-1), rc = st.query(median+1, MAXN);
    return (ccr[median]*lc.s - lc.f) + (rc.f - ccr[median]*rc.s);
}
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    int len = n-k+1;
 
    vector<int> nums(n);
    for(int &i : nums) cin >> i;
    set<int> snums; for(int num : nums) snums.insert(num);
    for(int num : snums) ccr[++id] = num, cc[num] = id;
 
    for(int i=0; i<k; i++) {
        ost.insert(cc[nums[i]]);
        st.update(cc[nums[i]], cc[nums[i]], {nums[i], 1});
    }
    ans = vector<int>(len); ans[0] = cost();
    for(int i=k; i<n; i++) {
        int sz = ost.size();
        ost.erase(cc[nums[i-k]]); st.update(cc[nums[i-k]], cc[nums[i-k]], {-nums[i-k], -1});
        ost.insert(cc[nums[i]]); st.update(cc[nums[i]], cc[nums[i]], {nums[i], 1});
        ans[i-k+1] = cost();
    }
 
    for(int i=0; i<len; i++) cout << ans[i] << " \n"[i == len-1];
    return 0;
}
