#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
#define f first
#define s second
#define sz(x) (int)(x.size())
 
const int MOD = 1e9+7;
 
int n, m;
vi zero = {0}, one = {1};
 
vvvi mmemo;
vi& genMasks(int idx, int mask) {
    if(idx == n) return zero;
    if(sz(mmemo[idx][mask])) return mmemo[idx][mask];
    vi ans;
    if((mask & (1 << idx)) == 0) {
        vi next = genMasks(idx+1, mask);
        for(int nmask : next) ans.push_back(nmask + (1 << idx));
        return mmemo[idx][mask] = ans;
    }
    if(idx < n-1 && ((mask & (1 << idx)) && (mask & (1 << (idx+1))))) {
        vi next = genMasks(idx+2, mask);
        for(int nmask : next) ans.push_back(nmask + (1 << idx) + (1 << (idx+1)));
    }
    vi next = genMasks(idx+1, mask);
    for(int nmask : next) ans.push_back(nmask);
    return mmemo[idx][mask] = ans;
}
 
vvi memo;
int DP(int idx, int mask) {
    if(idx == m-1) {
        int nmask = 0, ok = 1;
        for(int i=0; i<n; i++)
            if((mask & (1 << i)) == 0)
                nmask += (1 << i);
        for(int i=0; i<n-1; i++) {
            if((nmask & (1 << i)) == 0) {
                if((nmask & (1 << (i+1)))) {
                    ok = 0;
                    break;
                }
                i++;
            }
        }
        return ok;
    }
    if(memo[idx][mask] != -1) return memo[idx][mask];
    int ans = 0;
    vi masks = genMasks(0, mask);
    for(int nmask : masks) {
        ans += DP(idx+1, nmask);
        ans %= MOD;
    }
    return memo[idx][mask] = ans;
}
 
int main() {
    cin >> n >> m;
    memo = vvi(m, vi(1 << n, -1));
    mmemo = vvvi(n, vvi(1 << n));
    cout << ((n&1) && (m&1) ? 0 : DP(0, (1 << n) - 1)) << endl;
    return 0;
}
