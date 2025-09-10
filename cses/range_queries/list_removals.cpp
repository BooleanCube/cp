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

#include <bits/extc++.h>
using namespace __gnu_pbds;

struct multiost {
    typedef tree<
        pair<pii, int>,
        null_type,
        less<pair<pii, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ost;

    ost s;
    unsigned cnt = 0;

    multiost() = default;
    multiost(initializer_list<pii> l) { for(pii x : l) insert(x); }
    void insert(pii x) { s.insert({x, cnt++}); }
    ost::iterator find_by_order(int k) { return s.find_by_order(k); }
    int order_of_key(pii k) { return s.order_of_key({k, 0}); }
    void erase(pii x) {
        auto it = s.lower_bound({x, 0});
        // erase(it); // erases only first element
        while(it != s.end() && it->first == x) erase(it++); // erases all elements
    }
    void erase(ost::iterator it) { s.erase(it); }
    size_t size() const { return s.size(); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    multiost ost;
    rep(i, 0, n) {
        int x; cin >> x;
        ost.insert({i, x});
    }
    vi ans(n);
    rep(i, 0, n) {
        int q; cin >> q;
        auto it = ost.find_by_order(q-1);
        ans[i] = it->f.s;
        ost.erase(it);
    }
    rep(i, 0, n) cout << ans[i] << " \n"[i==n-1];
    return 0;
}