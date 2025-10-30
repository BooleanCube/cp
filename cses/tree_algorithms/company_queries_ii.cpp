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


// make sure tree is rooted at index 0 for par array input
struct BL {
  int n, L;
  vi ht;
  vector<vi> jmp;
  BL(int N, vi &P) : n(N), L(__lg(N)+1) {
    jmp = vector<vi>(N, vi(L)); ht = vi(N);
    rep(i, 0, n) jmp[i][0] = P[i], climb(P, i);
    rep(j, 1, L) rep(i, 0, n) jmp[i][j] = jmp[jmp[i][j-1]][j-1];
  }
  int climb(vi &p, int u) {
    if(!u) return 0;
    if(ht[u]) return ht[u];
    return ht[u] = climb(p, p[u]) + 1;
  }
  int kth(int u, int k) {
    for(; k; k -= k&-k) u = jmp[u][__builtin_ctz(k)];
    return u;
  }
  int lca(int u, int v, int k = 1) {
    if(ht[v] < ht[u]) swap(u, v);
    if(ht[u] < ht[v]) return lca(u, kth(v, ht[v] - ht[u]));
    if(u == v) return u;
    while(kth(u, 1LL<<k) != kth(v, 1LL<<k)) k++; k--;
    return lca(kth(u, 1LL<<k), kth(v, 1LL<<k));
  }
  int dist(int u, int v) { return ht[u] + ht[v] - ht[lca(u, v)]; }
};

void solve() {
  int n, q; cin >> n >> q;
  vi p(n); rep(i, 1, n) cin >> p[i], p[i]--;
  BL bl(n, p);
  while(q--) {
    int a, b; cin >> a >> b; a--, b--;
    cout << bl.lca(a, b) + 1 << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  solve();
}
