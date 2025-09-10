#include <bits/stdc++.h>
#include <iterator>
#include <set>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    multiset<int> tickets;
    for(int i=0; i<n; i++) {
        int t; cin >> t;
        tickets.insert(t);
    }
    for(int i=0; i<m; i++) {
        int p; cin >> p;
        auto it = tickets.upper_bound(p);
        if(it == begin(tickets)) {
            cout << -1 << '\n';
            continue;
        }
        cout << *(--it) << '\n';
        tickets.erase(it);
    }
    return 0;
}
