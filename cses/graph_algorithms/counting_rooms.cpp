#include <bits/stdc++.h>

using namespace std;

int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
bool vis[1000][1000];
char rooms[1000][1000];

void dfs(int x, int y, int n, int m) {
    vis[x][y] = true;
    for(int i=0; i<4; i++){
        int dx = x+h[i], dy = y+v[i];
        if(0 <= dx && dx < n && 0 <= dy && dy < m && !vis[dx][dy] && rooms[dx][dy]=='.')
            dfs(dx, dy, n, m);
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin >> c;
            vis[i][j] = 0;
            rooms[i][j] = c;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && rooms[i][j]=='.'){
                dfs(i, j, n, m);
                ans++;
            }
        }
    }
    cout << ans << endl;
}
