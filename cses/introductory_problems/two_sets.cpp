#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    ll s = n*(n+1)/2;
    if(s&1) cout << "NO\n";
    else {
        ll rem = s/2;
        vector<int> a, b;
        while(n) {
            if(rem >= n) { rem -= n; a.emplace_back(n); n--; }
            else { b.emplace_back(n); n--; }
        }
        cout << "YES\n";
        cout << a.size() << endl;
        for(int i=0; i<a.size(); i++) cout << a[i] << " \n"[i==(a.size()-1)];
        cout << b.size() << endl;
        for(int i=0; i<b.size(); i++) cout << b[i] << " \n"[i==(b.size()-1)];
    }
    return 0;
}