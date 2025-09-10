#include <bits/stdc++.h>
using namespace std;

bool inBounds(int x, int y, int n) {
    return x>-1 && y>-1 && x<n && y<n;
}

int main() {
    int n; cin >> n;
    char map[n][n];
    int count[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
            count[i][j] = 0;
        }
    }
    count[0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == '*') { count[i][j]=0; continue; }
            if(inBounds(i-1,j,n) && map[i-1][j]!='*') count[i][j] += count[i-1][j];
            if(inBounds(i,j-1,n) && map[i][j-1]!='*') count[i][j] += count[i][j-1];
            count[i][j] %= 1000000007;
        }
    }
    cout << count[n-1][n-1] << endl;
    return 0;
}
