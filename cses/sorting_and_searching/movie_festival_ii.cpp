#include <bits/stdc++.h>
#include <utility>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    multiset<int> current;
    for(int i=0; i<k; i++) current.insert(1);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = make_pair(b, a);
    }
    sort(movies.begin(), movies.end());
    int counter = 0;
    for(pair<int,int> movie : movies) {
        auto it = current.upper_bound(movie.second);
        if(it == begin(current)) continue;
        current.erase(--it);
        current.insert(movie.first);
        counter++;
    }
    cout << counter << endl;
}
