#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define f first
#define s second
#define spc <<" "<<
#define endl "\n" // remove when debugging


struct SCC {
    int N;
    vector<vector<int>> adj, radj;
    vector<int> todo, comp, comps;
    vector<bool> vis;
    SCC(int n) : N(n) { adj.resize(N), radj.resize(N), comp = vector<int>(N, -1), vis.resize(N); }
    void addEdge(int u, int v) { adj[u].push_back(v), radj[v].push_back(u); }
    void dfs(int u) {
        vis[u] = 1;
        for(int v : adj[u]) if (!vis[v]) dfs(v);
        todo.push_back(u);
    }
    void dfs2(int u, int c) {
        comp[u] = c;
        for(int v : radj[u]) if (comp[v] == -1) dfs2(v, c);
    }
    void gen() {  // fills allComp
        rep(i, 0, N) if (!vis[i]) dfs(i);
        reverse(all(todo));
        for(int u : todo) if (comp[u] == -1) { dfs2(u, u), comps.push_back(u); }
    }
};

int main() {
  int n, m; cin >> n >> m;
  SCC scc(n);
  rep(i, 0, m) {
    int u, v; cin >> u >> v; u--, v--;
    scc.addEdge(u, v);
  }
  scc.gen();
  int ID[200000]{};
	int ids = 0;
	for (int i = 0; i < n; i++) {
		if (!ID[scc.comp[i]]) { ID[scc.comp[i]] = ++ids; }
	}
	cout << ids << '\n';
	for (int i = 0; i < n; i++) { cout << ID[scc.comp[i]] << " \n"[i == n - 1]; }
  return 0;
}
