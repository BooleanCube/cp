#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n, k, p2;
vector<int> seg;

void update(int idx, int x) {
    idx += p2;
    while(idx) {
        seg[idx] += x;
        idx >>= 1; 
    }
}

int query(int kth) {
    int idx = 1, look = kth;
    while(idx < p2) {
        if(seg[idx*2] >= look) idx = idx*2;
        else {
            look -= seg[idx*2];
            idx = idx*2+1;
        }
    }
    return idx-p2+1;
}

int main() {
    cin >> n >> k;
    p2 = pow(2, ceil(log2(n)));
    seg = vector<int>(2*p2);
    vi ans;
    for(int i=0; i<n; i++) update(i, 1);
    int idx = (k)%n;
    while(ans.size() < n) {
        int kth = query(idx+1);
        ans.emplace_back(kth);
        if(ans.size() == n) break;
        idx += k;
        idx %= (n-ans.size());
        update(kth-1, -1);
    }
    for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];
    return 0;
}