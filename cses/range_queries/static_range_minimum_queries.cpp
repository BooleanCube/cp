#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
 
typedef long long ll;
 
void constructTree(vector<ll>& tree, ll n) {
    for(int i=n; i<=2*n; i++) {
        int b = i;
        ll c = tree[i];
        while(b>1) {
            b>>=1;
            tree[b] = min(tree[b], c);
        }
    }
}
 
ll getMin(vector<ll>& tree, int a, int b, ll m) {
    if(a==b) return min(m, tree[a]);
    if(a%2 == 1) { m = min(m, tree[a]); a++; }
    if(a==b) return min(m, tree[b]);
    if(b%2 == 0) { m = min(m, tree[b]); b--; }
    return getMin(tree, a>>1, b>>1, m);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,q; cin >> n >> q;
    vector<ll> tree(2*n+1, LLONG_MAX);
    for(int i=0; i<n; i++) cin >> tree[n+i];
    constructTree(tree, n);
    string r="";
    for(int i=0; i<q; i++) {
        int a,b; cin >> a >> b;
        r.append(to_string(getMin(tree, a+n-1, b+n-1, LLONG_MAX))).append("\n");
    }
    cout << r;
}