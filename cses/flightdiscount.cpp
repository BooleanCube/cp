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
#define sp <<" "<<
#define endl "\n" // remove when debugging

const ll INF = 1e16;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pll>> graph(n), graph2(n);
    rep(i, 0, m) {
        ll a, b, w; cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
        graph2[b].push_back({a, w});
    }
    vector<ll> dist1(n, INF), dist2(n, INF);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [cd, cu] = pq.top(); pq.pop();
        if(dist1[cu] <= cd) continue;
        dist1[cu] = cd;
        for(auto [nv, wt] : graph[cu]) {
            if(dist1[nv] <= cd + wt) continue;
            pq.push({cd + wt, nv});
        }
    }
    pq.push({0, n-1});
    while(!pq.empty()) {
        auto [cd, cu] = pq.top(); pq.pop();
        if(dist2[cu] <= cd) continue;
        dist2[cu] = cd;
        for(auto [nv, wt] : graph2[cu]) {
            if(dist2[nv] <= cd + wt) continue;
            pq.push({cd + wt, nv});
        }
    }
    ll ans = INF;
    for(int u=0; u<n; u++) {
        for(auto [v, w] : graph[u]) {
            ans = min(ans, dist1[u] + (w / 2) + dist2[v]);
        }
    }
    // for(int i=0; i<n; i++) cout << "{" << i << " " << dist1[i] << "}" << endl;
    cout << ans << endl;
    return 0;
}
