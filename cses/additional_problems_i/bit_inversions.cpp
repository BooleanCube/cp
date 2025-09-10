#include <bits/stdc++.h>
using namespace std;

#define sp <<" "<<

int n;
set<int> endps;
multiset<int> subs;

void update(int x) {
	if(x==0 || x==n) return;
	auto it = endps.find(x);
	if(it != endps.end()) {
		int a = *(--it)++, b = *(++it)--;
		// cout << a sp b sp x-a sp b-x << endl;
		if(subs.find(x-a) != subs.end()) subs.erase(subs.find(x-a));
		if(subs.find(b-x) != subs.end()) subs.erase(subs.find(b-x));
		subs.insert(b-a);
		endps.erase(it);
	} else {
		it = endps.insert(x).first;
		int a = *(--it)++, b = *(++it)--;
		if(subs.find(b-a) != subs.end()) subs.erase(subs.find(b-a));
		subs.insert(x-a); subs.insert(b-x);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; int m; cin >> s >> m;
	n = s.size();
	endps.insert(0); endps.insert(n);
	for(int i=0; i<n-1; i++)
		if(s[i] != s[i+1])
            endps.insert(i+1);
	for(auto it=endps.begin(); ++it!=endps.end();)
		subs.insert(*(++it)-- - *it);
	for(int i=0; i<m; i++) {
		int x; cin >> x;
		update(x-1); update(x);
		// cout << "hello\n";
		cout << *(--subs.end()) << " \n"[i==m-1];
	}
    return 0;
}
