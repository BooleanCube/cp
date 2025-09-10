#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<vector<int>> edges;
vector<int> ht, sub, ans;

int dfs(int p, int c, int h) {
    if(ht[c] > -1) return 0;
    ht[c] = h;
    int cnt = 1;
    for(int nbr : edges[c]) {
        if(nbr == p) continue;
        cnt += dfs(c, nbr, h+1);
    }
    return sub[c] = cnt;
}

void dpdfs(int p, int c) {
    ans[c] = ans[p] + (-sub[c] + (n-sub[c]));
    for(int nbr : edges[c]) {
        if(nbr == p) continue;
        dpdfs(c, nbr);
    }
}

signed main() {
    cin >> n;
    edges = vector<vector<int>>(n, vector<int>(0));
    ht = vector<int>(n, -1), sub = vector<int>(n), ans = vector<int>(n);
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    dfs(-1, 0, 0);
    for(int i=0; i<n; i++) ans[0] += ht[i];
    for(int nbr : edges[0]) dpdfs(0, nbr);
    for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];
    return 0;
}