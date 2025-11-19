#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second

int n, x;
vector<int> w;
vector<pii> memo;

bool cur(pii a, pii b) { return a.f==b.f && a.s==b.s; }

pii DP(int mask) {
	if(mask == 0) return {1, 0};
	if(!cur(memo[mask], {-1, -1})) return memo[mask];
	pii ans = {1e9, 1e9};
	for(int i=0; i<n; i++) {
		if(mask & (1 << i)) {
			pii cur = DP(mask ^ (1 << i));
			if(cur.s + w[i] > x) cur = {cur.f+1, w[i]};
			else cur.s += w[i];
			ans = min(ans, cur);
		}
	}
	return memo[mask] = ans;
}

int main() {
	cin >> n >> x;
	memo = vector<pii>(1 << n, {-1, -1});
	w = vector<int>(n);
	for(int &i : w) cin >> i;
	cout << DP((1 << n) - 1).f << endl;
	return 0;
}
