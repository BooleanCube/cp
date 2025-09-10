// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

string path;
vector<vector<int>> vis(7, vector<int>(7));
int ans = 0;

int adj[4] = {1, -1, 0, 0};
string dirs = "DULR";

bool valid(int x, int y) { return x>=0 && x<7 && y>=0 && y<7; }
bool checkLoops(int i, int j) {
	return (valid(i-1,j) && !vis[i-1][j] && valid(i+1,j) && !vis[i+1][j] &&
			(!valid(i,j-1) || vis[i][j-1]) && (!valid(i,j+1) || vis[i][j+1])) ||
		   ((!valid(i-1,j) || vis[i-1][j]) && (!valid(i+1,j) || vis[i+1][j]) &&
			valid(i,j-1) && !vis[i][j-1] && valid(i,j+1) && !vis[i][j+1]);
}
void backtrack(int idx, int i, int j) {
	// pruning
	if(48-idx < abs(6-i)+j) return;
	if(i == 6 && j == 0 && idx < 48) return;
	if(checkLoops(i, j)) return;
	
	// base case
	if(idx == 48 && i == 6 && j == 0) {
		++ans;
		return;
	}

	// state transitions
	vis[i][j] = 1;
	if(path[idx] == '?') {
		for(int k=0; k<4; k++) {
			int dx = adj[k], dy = adj[3-k];
			if(valid(i+dx, j+dy) && !vis[i+dx][j+dy])
				backtrack(idx+1, i+dx, j+dy);
		}
	} else {
		int k = dirs.find(path[idx]);
		int dx = adj[k], dy = adj[3-k];
		if(valid(i+dx, j+dy) && !vis[i+dx][j+dy])
			backtrack(idx+1, i+dx, j+dy);
	}
	vis[i][j] = 0;
}

int main() {
	cin >> path;
	backtrack(0, 0, 0);
	cout << ans << endl;
}
