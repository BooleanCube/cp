#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> x(n+1);
    x[0] = -1;
    int cnt = 1;
    for(int i=1; i<=n; i++) {
        int c; cin >> c;
        x[c] = i;
    }
    for(int i=1; i<=n; i++) if(x[i-1]>x[i]) cnt++;
    cout << cnt << endl;
    return 0;
}
