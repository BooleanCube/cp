#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> vis;
vector<int> cols;

bool dfs(int cur, int col) {
    if(vis[cur]) return true;
    vis[cur] = 1;
    for(int nbr : graph[cur])
        if(cols[nbr] == col+1) return false;
    cols[cur] = col+1;
    bool works = 1;
    for(int nbr : graph[cur]) {
        if(vis[nbr]) continue;
        works = works && dfs(nbr, !col);
    }
    return works;
}

int main() {
    int n, m; cin >> n >> m;
    graph = vector<vector<int>>(n);
    vis = cols = vector<int>(n);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        graph[a-1].emplace_back(b-1);
        graph[b-1].emplace_back(a-1);
    }
    bool ans = 1;
    for(int i=0; i<n; i++)
        ans = ans && dfs(i, 0);
    if(ans) {
        for(int i=0; i<n; i++)
            cout << cols[i] << " \n"[i == n-1];
    }
    else cout << "IMPOSSIBLE\n";
    return 0;
}