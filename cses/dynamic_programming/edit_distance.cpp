#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    vector<vector<int>> DP(s.size()+1, vector<int>(t.size()+1));
    for(int i=0; i<=s.size(); i++) DP[i][0] = i;
    for(int i=0; i<=t.size(); i++) DP[0][i] = i;
    for(int i=1; i<=s.size(); i++) {
        for(int j=1; j<=t.size(); j++) {
            if(s[i-1] == t[j-1]) DP[i][j] = DP[i-1][j-1];
            else DP[i][j] = 1 + min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1]));
        }
    }
    cout << DP[s.size()][t.size()] << endl;
    return 0;
}
