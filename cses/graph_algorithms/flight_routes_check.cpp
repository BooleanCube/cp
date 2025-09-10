#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g1(n+1, vector<int>(0));
    vector<vector<int>> g2(n+1, vector<int>(0));
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        g1[a].emplace_back(b);
        g2[b].emplace_back(a);
    }
    deque<int> q; q.push_back(1);
    vector<bool> vis(n+1);
    while(!q.empty()) {
        int cur = q.front(); q.pop_front();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(int nbr : g1[cur]) {
            if(vis[nbr]) continue;
            q.push_back(nbr);
        }
    }
    int unvis = -1;
    for(int i=1; i<=n; i++)
        if(!vis[i]) unvis = i;
    if(unvis > -1) {
        cout << "NO\n1 " << unvis << endl;
        return 0;
    }
    q.push_back(1);
    vis = vector<bool>(n+1);
    while(!q.empty()) {
        int cur = q.front(); q.pop_front();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(int nbr : g2[cur]) {
            if(vis[nbr]) continue;
            q.push_back(nbr);
        }
    }
    unvis = -1;
    for(int i=1; i<=n; i++)
        if(!vis[i]) unvis = i;
    if(unvis > -1) {
        cout << "NO\n" << unvis << " 1" << endl;
        return 0;
    }
    cout << "YES\n";
    return 0;
}