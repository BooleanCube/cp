#include <bits/stdc++.h>
using namespace std;

// #define int long long
using vi = vector<int>;
#define sz(x) (int)(x.size())
#define sp <<" "<<

int n, m, id = 0;
vector<vi> graph, ans;
vi vis, out;

void dfs(int cur, int par) {
    if(vis[cur]) return;
    vis[cur] = ++id;
    for(int nbr : graph[cur]) {
        if(nbr == par) continue;
        // use the child node to connect old nodes so you can update outdegrees
        if(vis[nbr] && vis[cur] > vis[nbr]) {
            ans[cur].push_back(nbr);
            out[cur]++;
        }
        // else if it hasn't been visited...
        else if(!vis[nbr]) {
            dfs(nbr, cur);
            // connect the child if it has an odd outdegree
            if(out[nbr] & 1) {
                ans[nbr].push_back(cur);
                out[nbr]++;
            }
            // else connect the current node to it's child
            else {
                ans[cur].push_back(nbr);
                out[cur]++;
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    graph = vector<vi>(n+1, vi(0)), ans = vector<vi>(n+1, vi(0));
    vis = vi(n+1), out = vi(n+1);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++) dfs(i, 0);
    int w = 0;
    for(int i : out) w |= (i & 1);
    if(w) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i=1; i<=n; i++)
        for(int j : ans[i])
            cout << i sp j << endl;
    return 0;
}
