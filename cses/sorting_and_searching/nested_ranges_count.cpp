#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct MultiOST {
    typedef pair<int, unsigned> pii; // pair.first holds the value of the element
    typedef tree<
        pii,
        null_type,
        less<pii>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ost;

    ost s;
    unsigned cnt = 0;

    MultiOST() = default;
    MultiOST(initializer_list<int> l) { for(int x : l) insert(x); }
    void insert(int x) { s.insert({x, cnt++}); }
    ost::iterator find_by_order(int k) { return s.find_by_order(k); }
    int order_of_key(int k) { return s.order_of_key({k, 0}); }
    void erase(int x) {
        auto it = s.lower_bound({x, 0});
        // erase(it); // erases only 1 element
        while(it != s.end() && it->first == x) erase(it++);
    }
    void erase(ost::iterator it) { s.erase(it); }
    size_t size() const { return s.size(); }
};

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

#define all(x) begin(x),end(x)
#define sz(x) (int)(x.size())

int main() {
    int n; cin >> n;
    vector<array<int, 3>> pts(n);
    for(int i=0; i<n; i++) {
        cin >> pts[i][1] >> pts[i][0];
        pts[i][1] *= -1;
        pts[i][2] = i;
    }
    sort(all(pts));
    MultiOST sp, ep;
    vector<int> rin(n), rout(n);
    for(int i=0; i<n; i++) {
        auto [e, s, idx] = pts[i];
        s *= -1;
        int cnt = sz(sp) - sp.order_of_key(s);
        // cout << "cnt " << cnt << endl;
        rin[idx] += cnt;
        sp.insert(s);
    }
    for(auto &p : pts) {
        p[1] *= -1;
        swap(p[0], p[1]);
        p[1] *= -1;
    }
    sort(all(pts));
    for(int i=0; i<n; i++) {
        auto [s, e, idx] = pts[i];
        e *= -1;
        int cnt = sz(ep) - ep.order_of_key(e);
        // cout << "ecnt " << cnt << endl;
        rout[idx] += cnt;
        ep.insert(e);
    }
    for(int i=0; i<n; i++) cout << rin[i] << " \n"[i==n-1];
    for(int i=0; i<n; i++) cout << rout[i] << " \n"[i==n-1];
    return 0;
}
