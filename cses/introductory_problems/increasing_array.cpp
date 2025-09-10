#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll a; cin >> a;
	ll s = 0, p = 0;
	for(int i=0; i<a; i++) {
		ll x; cin >> x;
		if(x < p) s+=p-x, p-=x;
		else p = 0;
		p+=x;
	}
	cout << s << endl;
}
