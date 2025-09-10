#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
#define f first
#define s second
#define sz(x) (int)(x.size())

string cfill(string s, int n, char c) {
    while(sz(s) < n) s = c + s;
    return s;
}

vvi memo(19, vi(10, -1));
string curs = cfill("", 19, '0'), curb = cfill("", 19, '9'), a, b;
int asz, bsz;

bool match(int idx) {
    return idx && ((19-idx <= asz && curs.substr(0, idx-1) == a.substr(0, idx-1)) || (19-idx <= bsz && curb.substr(0, idx-1) == b.substr(0, idx-1)));
}

int DP(int idx, int pd, int flag) {
    if(curs > b || curb < a) return 0;
    if(idx == 19) return 1;
    if(pd > -1 && !match(idx) && memo[idx][pd] != -1) return memo[idx][pd];
    int ans = 0;
    for(int i=0; i<=9; i++) {
        if(i == pd) continue;
        curs[idx] = i+'0'; curb[idx] = i+'0';
        int tflag = flag && (i == 0);
        ans += DP(idx+1, (tflag ? -1 : i), tflag);
        curs[idx] = '0'; curb[idx] = '9';
    }
    if(match(idx) || pd < 0) return ans;
    return memo[idx][pd] = ans;
}

signed main() {
    cin >> a >> b; asz = sz(a), bsz = sz(b);
    a = cfill(a, 19, '0'); b = cfill(b, 19, '0');
    cout << DP(0, -1, 1) << endl;
    return 0;
}
