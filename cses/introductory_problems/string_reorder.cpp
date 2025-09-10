#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> m(26); for(auto u : s) m[u - 'A']++;
    string ans = "";
    for(int i=0; i<n; i++) {
        auto itr = max_element(m.begin(), m.end());
        int mx = *itr, chr = itr - m.begin();
        if(mx > (n - i) / 2) {
            map<int, int> mp; for(int j=0; j<26; j++) if(j != chr and m[j]) mp[j] = m[j];
            // cout << i << " here" << endl;
            while(ans.size() < n) {
                if(ans.empty() || ans.back() != 'A' + chr) {
                    ans += 'A' + chr; mx--;
                }
                else {
                    if(mp.empty()) {
                        cout << -1 << endl;
                        return 0;
                    }
                    int dchr = mp.begin()->first;
                    ans += 'A' + dchr; mp[dchr]--;
                    if(!mp[dchr]) mp.erase(dchr);
                }
            }
            break;
        }
        int cur = -1;
        for(int j=0; j<26; j++) {
            if(!m[j] or (ans.size() && 'A'+j == ans.back())) continue;
            cur = j;
            break;
        }
        if(cur == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans += 'A' + cur;
        m[cur]--;
    }
    cout << ans << endl;
}