#include <iostream>
#include <vector>
using namespace std;

int convertIdx(int x, int y, int n) { return (x-1)*n + y; }

int main() {
    int n, q; cin >> n >> q;
    vector<int> trees(n*n, 0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char c; cin >> c;
            int idx = convertIdx(i,j, n);
            if(c == '*') trees[idx] = trees[idx-1]+1;
            else trees[idx] = trees[idx-1];
        }
    }
    for(int i=0; i<q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0; 
        for(int y=x1; y<=x2; y++) {
            int left = convertIdx(y, y1, n), right = convertIdx(y, y2, n);
            sum += trees[right]-trees[left - 1];
        }
        cout << sum << endl;
    }
    return 0;
}
