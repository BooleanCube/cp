#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> k(n);
    multiset<int> towers;
    int cnt = 1;
    for(int i=0; i<n; i++) cin >> k[i];
    towers.insert(k[0]);
    for(int i=1; i<n; i++) {
        auto it = towers.upper_bound(k[i]);
        if(it == end(towers)) cnt++;
        else towers.erase(it);
        towers.insert(k[i]);
    }
    cout << cnt << endl;
    return 0;
}
