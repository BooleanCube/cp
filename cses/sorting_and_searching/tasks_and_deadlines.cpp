#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> tasks(n);
    for(int i=0; i<n; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());
    long long sum = 0;
    long long current = 0;
    for(int i=0; i<n; i++) {
        current += tasks[i].first;
        sum += tasks[i].second - current;
    }
    cout << sum << endl;
}
