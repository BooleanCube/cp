#include <bits/stdc++.h>
#include <deque>
using namespace std;

vector<int> ps, ans, vis;

int main() {
    int n; cin >> n;
    ps = vector<int>(n);
    for(int i=0; i<n; i++) {
        cin >> ps[i];
        ps[i]--;
    }
    ans = vector<int>(n, -1);
    for(int s=0; s<n; s++) {
        if(s == ps[s]) ans[s] = 1;
        if(ans[s] > -1) continue;
        set<int> vis;
        stack<int> path; int cur = s;
        while(1) {
            if(vis.count(cur)) {
                int cycle = 1;
                vector<int> temp;
                while(path.top() != cur) {
                    int ncur = path.top(); path.pop();
                    cycle++;
                    temp.push_back(ncur);
                } path.pop();
                temp.push_back(cur);
                for(int i : temp) ans[i] = cycle;
                break;
            }
            if(ans[cur] > -1) break;
            path.push(cur);
            vis.insert(cur);
            cur = ps[cur];
        }
        while(!path.empty()) {
            int prev = path.top(); path.pop();
            ans[prev] = ans[ps[prev]]+1;
        }
    }
    for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
