// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board(8, vector<int>(8));
vector<vector<int>> state(8, vector<int>(8));
int adj[4] = {1, -1, -1, 1};
int ans = 0, cnt = 0;

bool valid(int x, int y) { return 0<=x && x<8 && 0<=y && y<8; }
void backtrack(int i, int j) {
	if(cnt > 8) return;
	if(j>=8) j=0, i++;
	if(i>=8) {
		if(cnt == 8) ans++;
		return;
	}
	if(!board[i][j] || state[i][j]) backtrack(i, j+1);
	else {
		vector<array<int, 2>> updates;
		for(int k=0; k<8; k++) {
			if(!state[i][k]) {
				state[i][k] = 1;
				updates.push_back({i, k});
			}
			if(!state[k][j]) {
				state[k][j] = 1;
				updates.push_back({k, j});
			}
			for(int l=0; l<4; l++) {
				int dx = adj[(l+1)%4], dy = adj[l];
				if(valid(i+dx*k, j+dy*k) && !state[i+dx*k][j+dy*k]) {
					state[i+dx*k][j+dy*k] = 1;
					updates.push_back({i+dx*k, j+dy*k});
				}
			}
		}
		cnt++;
		backtrack(i, j+1);
		cnt--;
		for(auto upd : updates) state[upd[0]][upd[1]] = 0;
		backtrack(i, j+1);
	}
}

int main() {
	for(int i=0; i<8; i++) {
		string line; cin >> line;
		for(int j=0; j<8; j++) board[i][j] = (line[j]=='.');
	}
	backtrack(0, 0);
	cout << ans << endl;
	return 0;
}
