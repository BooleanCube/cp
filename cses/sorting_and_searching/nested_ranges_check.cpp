#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<array<int, 3>> vp;
#define sp <<" "<<

int main() {
    int n; cin >> n;
    vp pts(n);
    for(int i=0; i<n; i++) {
        cin >> pts[i][1] >> pts[i][0];
        pts[i][1] *= -1;
        pts[i][2] = i;
    }
    sort(pts.begin(), pts.end());
    int fsp = 0, lep = 0;
    vi rin(n), rout(n);
    for(int j=0; j<n; j++) {
        auto [e, s, i] = pts[j];
        s *= -1;
        if(s <= fsp) rin[i]++;
        else fsp = s;
        // cout << s sp e sp i sp fsp << endl;
    }
    for(auto &p : pts) {
        p[1] *= -1;
        swap(p[0], p[1]);
        p[1] *= -1;
    }
    sort(pts.begin(), pts.end());
    for(int j=0; j<n; j++) {
        auto [s, e, i] = pts[j];
        e *= -1;
        if(e <= lep) rout[i]++;
        else lep = e;
        // cout << s sp e sp i sp lep << endl;
    }
    for(int i=0; i<n; i++) cout << rin[i] << " \n"[i==n-1];
    for(int i=0; i<n; i++) cout << rout[i] << " \n"[i==n-1];
    return 0;
}
