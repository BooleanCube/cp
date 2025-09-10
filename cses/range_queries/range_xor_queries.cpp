#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<int> nums(n), psum(n+1);
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        nums[i] = a;
        psum[i+1] = psum[i]^a;
    }
    for(int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        cout << (psum[b] ^ psum[a-1]) << endl;
    }
    return 0;
}