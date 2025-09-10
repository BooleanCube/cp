#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;

void dfs(int cur, int cht, vector<int>& height) {
    if(height[cur] > 0) return;
    height[cur] = cht;
    for(int nbr : edges[cur]) {
        if(height[nbr] > 0) continue;
        dfs(nbr, cht+1, height);
    }
}

int main() {
    int n; cin >> n;
    edges = vector<vector<int>>(n+1, vector<int>(0));
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }
    queue<int> q; q.push(1);
    vector<int> vis(n+1, 0); int first = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(vis[cur]) continue;
        first = cur;
        vis[cur] = 1;
        for(int nbr : edges[cur]) {
            if(!vis[nbr])
                q.push(nbr);
        }
    }
    q.push(first);
    vis = vector<int>(n+1, 0); int last = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(vis[cur]) continue;
        last = cur;
        vis[cur] = 1;
        for(int nbr : edges[cur])
            if(!vis[nbr])
                q.push(nbr);
    }
    vector<int> ht1(n+1), ht2(n+1);
    dfs(first, 1, ht1);
    dfs(last, 1, ht2);
    for(int i=1; i<=n; i++) cout << max(ht1[i], ht2[i])-1 << " \n"[i==n];
    return 0;
}