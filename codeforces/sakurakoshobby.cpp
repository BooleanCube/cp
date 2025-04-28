#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int HMOD = 998244353;
const int MAXN = 1e5+5;
const double INF = 1e20;
const double EPS = 1e-9;

int getint() {
    int x;
    cin >> x;
    return x;
}

void getlist(vector<int> &lst, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }
}

vector<int> getstr(int n) {
    vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        lst[i] = c - '0';
    }
    return lst;
}

void findloop(vector<int>& memo, set<int>& vis, vector<int>& p, vector<int>& b, int idx) {
    if (memo[idx] != -1) return;
    if (vis.count(idx)) {
        int cur = p[idx], cnt = b[idx];
        while (cur != idx) {
            cnt += b[cur];
            cur = p[cur];
        }
        cur = p[idx];
        memo[idx] = cnt;
        while (cur != idx) {
            memo[cur] = cnt;
            cur = p[cur];
        }
        return;
    }
    vis.insert(idx);
    findloop(memo, vis, p, b, p[idx]);
}

int check(vector<int>& memo, vector<int>& p, vector<int>& b, int idx) {
    if (memo[idx] != -1) return memo[idx];
    memo[idx] = b[idx] + check(memo, p, b, p[idx]);
    return memo[idx];
}

void solve() {
    int n = getint();
    vector<int> p(n);
    getlist(p, n);
    for (int i = 0; i < n; ++i) {
        p[i]--;  // Adjust indexing from 1-based to 0-based
    }
    vector<int> b(n);
    string l; cin >> l;
    for (int i = 0; i < n; ++i) {
        b[i] = l[i] - '0';
        b[i] ^= 1;  // Perform XOR operation with 1
    }
    vector<int> memo(n, -1);
    for (int i = 0; i < n; ++i) {
        if (i == p[i]) {
            memo[i] = b[i];
            continue;
        }
        set<int> vis;
        findloop(memo, vis, p, b, i);
        check(memo, p, b, i);
    }
    for (int i = 0; i < n; ++i) {
        cout << memo[i] << " ";
    }
    cout << endl;
}

int main() {
    int testcases = 1;
    testcases = getint();
    for (int c = 1; c <= testcases; ++c) {
        solve();
    }
    return 0;
}

