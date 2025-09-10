#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n) {
    reverse(arr, arr + n);
}
 
int main() {
	int n, s; cin >> n >> s;
	int a[n], o[n];
	for(int i=0; i<n; i++) { cin >> a[i]; o[i] = a[i]; }
	sort(a, a+n);
	int l = 0, r = n-1;
	bool met = 0;
	while(l<r) {
		if(a[l] + a[r] == s) {
			int idxR = distance(o,find(o, o+n, a[r]))+1;
			reverse(o, n);
			int idxL = distance(o,find(o, o+n, a[l]))+1;
			cout << to_string(idxR) << " " << to_string(n-idxL+1) << endl;
			met = 1;
			break;
		}
		else if(a[l] + a[r] > s) r--;
		else if(a[l] + a[r] < s) l++;
	}
	if(!met) cout << "IMPOSSIBLE" << endl;
}