#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define int long long
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define pb push_back
#define F first
#define S second
#define sz size()
#define fastio ios_base::sync_with_stdio(false)
#define fr(i,s,e) for(int i=s; i<e; i++)

signed main() {
    fastio;
    int n; cin >> n;
    vi a, b;
    fr(i,0,n) {
        int s, e; cin >> s >> e;
        a.pb(s); b.pb(e);
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int m = 0, t = 0;
    int f = 0, s = 0;
    while(f<n) {
        if(a[f] <= b[s]) { f++; t++; }
        else { t--; s++; }
        m = max(m, t);
    }
    m = max(m, t);
    cout << m << endl;
    return 0;
}
