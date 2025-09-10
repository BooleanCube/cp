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

using namespace std;
using namespace __gnu_pbds;

struct multiost {
    typedef tree<
        pii,
        null_type,
        less<pii>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ost;

    ost s;
    unsigned cnt = 0;

    multiost() = default;
    multiost(initializer_list<int> l) { for(int x : l) insert(x); }
    void insert(int x) { s.insert({x, cnt++}); }
    ost::iterator find_by_order(int k) { return s.find_by_order(k); }
    int order_of_key(int k) { return s.order_of_key({k, 0}); }
    void erase(int x) {
        auto it = s.lower_bound({x, 0});
        erase(it); // erases only first element
        // while(it != s.end() && it->first == x) erase(it++); // erases all elements
    }
    void erase(ost::iterator it) { s.erase(it); }
    size_t size() const { return s.size(); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k; cin >> n >> k;
    multiost ost;
    vi p(n);
    for(int &x : p) {
        cin >> x;
        ost.insert(x);
    }
    while(k--) {
        char op; cin >> op;
        if(op == '!') {
            int i, j; cin >> i >> j; --i;
            ost.erase(p[i]);
            ost.insert(p[i] = j);
        } else {
            int a, b; cin >> a >> b;
            int c = ost.order_of_key(a), d = ost.order_of_key(b+1);
            cout << d - c << endl;
        }
    }
    return 0;
}
