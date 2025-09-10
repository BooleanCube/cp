#include<bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll, ll> seg[1000005];
ll lazy[1000005];

void dfs(ll k) {
    if (lazy[k]) {
        lazy[k] = 0;
        seg[2*k].first = seg[2*k + 1].first = seg[k].first/2;
        seg[2*k].second = 0; seg[2*k + 1].second = 0;
        lazy[2*k] = 1; lazy[2*k + 1] = 1;
    }   
}

void incrupdate(ll v, ll a, ll b, ll k, ll x, ll y) {
    if(b<x || a>y) return;
    if(a<=x && b>=y) {
        seg[k].second += v;
        return;
    }
    ll h = min(b,y)-max(a,x) + 1;
    dfs(k); 
    seg[k].first += h*v;
    incrupdate(v, a, b, 2*k, x, (x+y)/2);
    incrupdate(v, a, b, 2*k+1, (x+y)/2+1, y);
}

ll setupdate(ll v, ll a, ll b, ll k, ll x, ll y) {
    if(b<x || a>y) return seg[k].first + (y-x+1)*seg[k].second;
    if(a <= x && b >= y) {
        seg[k].first = (y-x+1)*v;
        seg[k].second = 0;
        lazy[k] = 1; 
        return seg[k].first;
    }
    dfs(k);
    seg[2*k].second += seg[k].second,  seg[2*k+1].second += seg[k].second;
    seg[k].second = 0;
    seg[k].first = setupdate(v, a, b, 2*k, x, (x+y)/2) + setupdate(v, a, b, 2*k + 1, (x+y)/2+1, y);
    return seg[k].first;

}

ll sum(ll a, ll b, ll k, ll x, ll y) {
    if(b < x || a > y) return 0;
    if(a <= x && b >= y) return seg[k].first + (y-x+1)*seg[k].second;
    dfs(k);
    seg[k].first += (y-x+1)*seg[k].second;
    seg[2*k].second += seg[k].second;seg[2*k+1].second += seg[k].second;
    seg[k].second = 0;
    return sum(a, b, 2*k, x, (x+y)/2) + sum(a, b, 2*k+1, (x+y)/2+1, y);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    int o = n;
    n = 1<<(ll)(ceil(log2(n)));
    for(int i=0; i<o; i++) {
        ll x; cin >> x;
        incrupdate(x, i, i, 1, 0, n-1);
    }
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            ll a, b, x; cin >> a >> b >> x;
            incrupdate(x, a-1, b-1, 1, 0, n-1);
        }
        else if(type == 2) {
            ll a,b,x; cin >> a >> b >> x;
            setupdate(x, a-1, b-1, 1, 0, n-1);
        }
        else if(type == 3) {
            ll a, b; cin >> a >> b;
            cout << sum(a-1, b-1, 1, 0, n-1) << '\n';
        }
    }
}