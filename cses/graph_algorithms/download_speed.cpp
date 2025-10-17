#include <bits/stdc++.h>
using namespace std;

#define int ll

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
#define sp <<" "<<
#define endl "\n" // remove when debugging
const int INF = 2e9;

struct FordFulkerson {
    using vp = vector<pii>;
    const int n, src, sink;
    vector<vi> adj, cap;
    FordFulkerson(int N, int S, int T) : n(N), src(S), sink(T) {
        adj = vector<vi>(n);
        cap = vector<vi>(n, vi(n));
    }
    void addEdge(int u, int v, int w) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += w;
    }
    int bfs(vi &par) {
        fill(all(par), -1); par[src] = -2;
        deque<pair<int, int>> q; q.push_back({src, INF});

        while (!q.empty()) {
            auto [u, w] = q.front(); q.pop_front();

            for (int v : adj[u]) {
                if(par[v] != -1 || cap[u][v] == 0) continue;

                par[v] = u;
                int flow = min(w, cap[u][v]);
                if(v == sink) return flow;
                q.push_back({v, flow});
            }
        }

        return 0;
    }
    int calc() {
        int flow = 0, cur = 0;
        vi par(n);

        while(cur = bfs(par)) {
            flow += cur;
            int v = sink;
            while(v != src) {
                int u = par[v];
                cap[u][v] -= cur;
                cap[v][u] += cur;
                v = u;
            }
        }

        return flow;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    FordFulkerson ff(n, 0, n-1);
    
    for(int i=0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        ff.addEdge(u, v, w);
    }

    cout << ff.calc() << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc = 1;
    while(tc--) solve();

    return 0;
}