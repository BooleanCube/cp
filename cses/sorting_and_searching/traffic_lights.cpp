// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, n; cin >> x >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	multiset<int> stops;
	stops.insert(0);
	for(int num : nums) stops.insert(num);
	stops.insert(x);
	int m = 0;
	int prev = 0;
	for(auto itr = stops.begin(); itr != stops.end(); ++itr) {
		int num = *itr;
		if(num == 0) continue;
		m = max(m, num-prev);
		prev = num;
	}
	vector<int> out(0);
	out.push_back(m);
	for(int i=n-1; i>0; i--) {
		auto it = stops.lower_bound(nums[i]);
		int start = *(--it);
		it++;
		int end = *(++it);
		stops.erase(--it);
		m = max(end-start, m);
		out.push_back(m);
	}
	for(int i=n-1; i>0; i--) {
		cout << out[i] << " ";
	}
	cout << out[0] << endl;
	return 0;
}
