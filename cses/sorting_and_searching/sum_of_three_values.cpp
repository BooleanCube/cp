#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
	ll n, s; 
	cin >> n >> s;
	pair<ll,ll> a[n];
	for(ll i=0; i<n; i++) { cin >> a[i].first; a[i].second = i+1; }
	sort(a, a+n);
	for(int i=0; i<n; i++) {
		ll l = 0, r = n-1;
		while(l<r && l<i && r>i) {
			ll comp = s-a[i].first;
			if(a[l].first+a[r].first == comp) {
				cout << a[l].second << " " << a[i].second << " " << a[r].second << endl;
				return 0;
			}
			else if(a[l].first+a[r].first > comp) r--;
			else l++;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}