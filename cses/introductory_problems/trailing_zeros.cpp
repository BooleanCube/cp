#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n; cin >> n;
    ll k = 1, sum = 0;
    while(pow(5,k) <= n) {
        sum += n/pow(5,k);
        ++k;
    }
    cout << sum << endl;
    return 0;
}
