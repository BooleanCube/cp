#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n; cin >> n;
    vector<array<int, 3>> customers;
    for(int i=0; i<n; i++) {
        int s, e; cin >> s >> e;
        customers.push_back({e, s, i});
    }
    sort(customers.begin(), customers.end());
    multimap<int, int> rooms; rooms.insert({0, 1});
    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        array<int, 3> cur = customers[i];
        int e = cur[0], s = cur[1], idx = cur[2];
        auto it = rooms.lower_bound(s);
        if(it == rooms.begin()) {
            rooms.insert({e, rooms.size()+1});
            ans[idx] = rooms.size();
        } else {
            it--;
            int roomNumber = it->second;
            rooms.erase(it);
            rooms.insert({e, roomNumber});
            ans[idx] = roomNumber;
        }
    }
    cout << rooms.size() << endl;
    for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
