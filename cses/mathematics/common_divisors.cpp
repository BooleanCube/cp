#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int divs[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		int a; cin >> a;
		int l = (int)sqrt(a);
		for(int d=l; d>0; d--) {
			if(a%d == 0) {
				divs[d]++;
				if(d != a/d) divs[a/d]++;
			}
		}
	}
	for(int i=1000000; i>=1; i--) {
		if(divs[i] >= 2) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}