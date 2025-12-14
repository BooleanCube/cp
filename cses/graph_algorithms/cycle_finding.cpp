#include <bits/stdc++.h>
using namespace std;


#define int long long

const int INF = 1e18;

void solve(int tcn) {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    vector<vector<int>> graph(n);
    for(int i=0; i<m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--, edges[i][1]--;
    }
    for(auto [u, v, c] : edges) graph[u].push_back(v);
    vector<int> dist(n), par(n); iota(par.begin(), par.end(), 0);
    int x = -1;
    // cout << "hi" << endl;
    for(int i=0; i<n; i++) {
        x = -1;
        for(auto [u, v, cost] : edges) {
            if(dist[u] + cost < dist[v]) {
                dist[v] = max(-INF, dist[u] + cost);
                par[v] = u;
                x = v;
            }
        }
    }
    // cout << "hi" << endl;
    if(x == -1) {
        cout << "NO" << endl;
        return;
    }
    for(int i=0; i<n; i++) x = par[x];
    vector<int> cycle; int v = x;
    while(v != x || cycle.empty()) {
        cycle.push_back(v);
        v = par[v];
    }
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << endl;
    for(int v : cycle) cout << v + 1 << " ";
    cout << cycle[0] + 1 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    for(int tcn=1; tcn<=tc; tcn++) {
        solve(tcn);
    }
    return 0;
}