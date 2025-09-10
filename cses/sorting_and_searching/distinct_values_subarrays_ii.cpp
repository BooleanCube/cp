// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	long long ans = 0;
	map<int, int> vis; int j = 0;
	for(int i=0; i<n; i++) {
		while(vis.size() <= k && j <= n) vis[nums[j++]]++;
		if(--vis[nums[j-1]] == 0) vis.erase(nums[--j]);
		ans += j-i;
		vis[nums[i]]--;
		if(vis[nums[i]] == 0) vis.erase(nums[i]);
	}
	cout << ans << endl;
}
