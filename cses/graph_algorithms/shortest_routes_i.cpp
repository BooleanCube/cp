#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
#define f first
#define s second

const int MAXD = 1e16;

signed main() {
    int n, m; cin >> n >> m;
    vvp graph(n+1);
    for(int i=0; i<m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    vi dist(n+1, MAXD);
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, 1});
    while(!pq.empty()) {
        auto [cdist, cur] = pq.top(); pq.pop();
        if(cdist >= dist[cur]) continue;
        dist[cur] = cdist;
        for(auto [nbr, ddist] : graph[cur]) pq.push({cdist+ddist, nbr});
    }
    for(int i=1; i<=n; i++) cout << dist[i] << " \n"[i==n];
    return 0;
}
