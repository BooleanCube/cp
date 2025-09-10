#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
vector<int> edges[MAXN];
vector<int> vis(MAXN, 0);
vector<int> taken(MAXN, 0);
int ans = 0;

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    for (int nbr : edges[cur]) {
        if (!vis[nbr]) {
            dfs(nbr);
            if (!taken[nbr] && !taken[cur]) {
                ans += 1;
                taken[nbr] = 1;
                taken[cur] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    dfs(0);
    
    cout << ans << "\n";

    return 0;
}