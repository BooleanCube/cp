#include<bits/stdc++.h>
using namespace std;

int update(vector<int>& ind, int x, int y, int r, int s, int c) {
    if(ind[r-1] <= ind[r] && ind[r-1] > y) c++;
    if(ind[r-1] > ind[r] && ind[r-1] <= y) c--;
    if(ind[r] <= ind[r+1] && y > ind[r+1]) c++;
    if(ind[r] > ind[r+1] && y <= ind[r+1]) c--;		
    ind[r] = y;
        
    if(ind[s-1] <= ind[s] && ind[s-1] > x) c++;
    if(ind[s-1] > ind[s] && ind[s-1] <= x) c--;
    if(ind[s] <= ind[s+1] && x > ind[s+1]) c++;
    if(ind[s] > ind[s+1] && x <= ind[s+1]) c--;	
    ind[s] = x;

    return c;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> ind(n+1);
    ind[0] = -1;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        ind[x] = i;
        a[i] = x;
    }
    int c = 1;
    for(int i=1; i<=n; i++) if(ind[i-1] > ind[i]) c++;
    for(int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        int r = a[x], s = a[y];
        swap(a[x], a[y]);

        c = update(ind, x, y, r, s, c);
        
        cout << c << endl;
    }
    return 0;
}
