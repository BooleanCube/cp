#include <bits/stdc++.h>
#include <cmath>
#include <ios>
using namespace std;
typedef long long ll;

long long int powl(ll l) { return l*l; }

int main (int argc, char *argv[]) {
    int n; cin >> n;
    cout << fixed;
    for(int i=0; i<n; i++) {
        ll x,y; cin >> x >> y;
        if(x>y) {
            if(x%2==0) cout << powl(x)-y+1 << endl;
            else cout << powl(x-1)+y << endl;
        } else {
            if(y%2==0) cout << powl(y-1)+x << endl;
            else cout << powl(y)-x+1 << endl;
        }
    }
    return 0;
}
