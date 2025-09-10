#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
using namespace std;

vector<vector<int>> edges;
vector<int> par;

int main() {
    int n, m; cin >> n >> m;
    edges = vector<vector<int>>(n+1, vector<int>(0));
    par = vector<int>(n+1);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    deque<int> q; q.push_back(1); par[1] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop_front();
        if(cur == n) break;
        for(int child : edges[cur]) {
            if(par[child]) continue;
            par[child] = cur;
            q.push_back(child);
        }
    }
    vector<int> ans;
    for(int i=n; i!=1; i=par[i]) {
        if(i == 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans.push_back(i);
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " \n"[i==ans.size()-1];
    return 0;
}
