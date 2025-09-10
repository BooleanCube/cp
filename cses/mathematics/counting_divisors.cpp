#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        int ans = 0;
        for(int i=1; i*i<x; i++) ans += !(x%i);
        ans *= 2;
        if(sqrt(x) == (int)sqrt(x)) ans += !(x % (int)sqrt(x));
        cout << ans << endl;
    }
    return 0;
}