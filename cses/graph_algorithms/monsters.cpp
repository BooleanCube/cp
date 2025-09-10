#include<bits/stdc++.h>
using namespace std;

vector<string> arr;
int n,m; 
bool safe(int x, int y) {
    if (x<0 || y<0 || x>=n || y>=m || arr[x][y] == '#') return false;
    return true;
}


int main() {
    
    cin >> n >> m;    
    arr.resize(n);    
    for(int i = 0; i<n; i++) {        
        cin >> arr[i];
    }
    
    vector<pair<int, int>> monsters;
    pair<int, int> start;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if (arr[i][j] == 'A') {
                start = {i,j};
            }
            if (arr[i][j] == 'M') {
                monsters.push_back({i,j});
            }
        }
    }
    vector<vector<int>> mondist(n, vector<int> (m,INT_MAX));
    
    queue<vector<int>> qm;
    for(auto i : monsters) {
        mondist[i.first][i.second] = 0;
        qm.push({i.first, i.second, 0});
    }

    while(qm.size()) {
        auto u = qm.front();
        qm.pop();
        int i = u[0], j = u[1], d = u[2];

        if (safe(i-1,j)) {
            if (d + 1 < mondist[i-1][j]) {
                mondist[i-1][j] = d + 1;
                qm.push({i-1,j, d+1});
            }
        }
        if (safe(i+1,j)) {
            if (d + 1 < mondist[i+1][j]) {
                mondist[i+1][j] = d + 1;
                qm.push({i+1,j, d+1});
            }
        }
        if (safe(i,j-1)) {
            if (d + 1 < mondist[i][j-1]) {
                mondist[i][j-1] = d + 1;
                qm.push({i,j-1, d+1});
            }
        }
        if (safe(i,j+1)) {
            if (d + 1 < mondist[i][j+1]) {
                mondist[i][j+1] = d + 1;
                qm.push({i,j+1, d+1});
            }
        }
    }

    queue<vector<int>> q;
    q.push({start.first, start.second, 0});
    vector<vector<char>> vis(n, vector<char> (m,'.'));
    vis[start.first][start.second] = 'A';
    
    int endx = -1, endy;
    while(q.size()) {
        auto u = q.front();
        q.pop();
        int i = u[0], j = u[1], d = u[2];

        if (i == 0 || j == 0 || i == n-1 || j == m-1) {
            endx = i, endy = j;
            break;
        }

        if (safe(i-1,j) && d+1 < mondist[i-1][j] && vis[i-1][j] == '.') {
            vis[i-1][j] = 'U';
            q.push({i-1,j,d+1});
        }
        if (safe(i+1,j) && d+1 < mondist[i+1][j] && vis[i+1][j] == '.') {
            vis[i+1][j] = 'D';
            q.push({i+1,j,d+1});
        }
        if (safe(i,j-1) && d+1 < mondist[i][j-1] && vis[i][j-1] == '.') {
            vis[i][j-1] = 'L';
            q.push({i,j-1,d+1});
        }
        if (safe(i,j+1) && d+1 < mondist[i][j+1] && vis[i][j+1] == '.') {
            vis[i][j+1] = 'R';
            q.push({i,j+1,d+1});
        }
    }
    
    if (endx == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        
        string ans;

        int i = endx, j = endy;

        while(vis[i][j] != 'A') {
            ans+=vis[i][j];
            if (vis[i][j] == 'R') j--;
            else if (vis[i][j] == 'L') j++;
            else if (vis[i][j] == 'D') i--;
            else i++;
        }

        reverse(ans.begin(), ans.end());
        cout << (ans.size()) << endl;
        cout << (ans) << endl;
    }
    

	return 0;
}