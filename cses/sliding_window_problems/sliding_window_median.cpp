#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
        for (int x : l) {
            insert(x);
        }
    }
    void insert(int x) {
        s.insert({x, cnt++});
    }
    ost::iterator find_by_order(int k) {
        return s.find_by_order(k);
    }
    // erase all elements with value x
    void erase(int x) {
        auto it = s.lower_bound({x, 0});
        erase(it);
        // while (it != s.end() && it->first == x) {
            // erase(it++);
        // }
    }
    // erase a single element
    void erase(ost::iterator it) {
        s.erase(it);
    }

    size_t size() const {
        return s.size();
    }
};

int main() {
    int n, k; cin >> n >> k;
    int len = n-k+1;
    vector<int> nums(n);
    for(int &i : nums) cin >> i;
    ost_multiset ost;
    for(int i=0; i<k; i++) ost.insert(nums[i]);
    vector<int> ans(len); ans[0] = ost.find_by_order((k-1)>>1)->first;
    for(int i=k; i<n; i++) {
        int sz = ost.size();
        ost.erase(nums[i-k]);
        ost.insert(nums[i]);
        ans[i-k+1] = ost.find_by_order((k-1)>>1)->first;
    }
    for(int i=0; i<len; i++) cout << ans[i] << " \n"[i == len-1];
    return 0;
}
