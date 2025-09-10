#include <bits/stdc++.h>
#include <string>
using namespace std;

string joinList(vector<string>& arr, string delimiter) {
    if (arr.empty()) return "";
    string str;
    for (auto i : arr)
        str += i + delimiter;
    str = str.substr(0, str.size() - delimiter.size());
    return str;
}

int find(vector<int>& parent, int x) {
	if(x == parent[x]) return x;
	return parent[x] = find(parent, parent[x]);
}

void merge(vector<int>& parent, int x, int y) {
	x = find(parent, x);
	y = find(parent, y);
	parent[x] = y;
}

int main() {
	int n,m; cin >> n >> m;
	vector<int> parent(n+1);
	for(int i=0; i<=n; i++) parent[i]=i;
	for(int i=0; i<m; i++) {
		int s,e; cin >> s >> e;
		merge(parent, s, e);
	}
	int x = find(parent, 1);
	vector<string>* res = new vector<string>();
	for(int i=1; i<=n; i++) {
		int y = find(parent, i);
		if(x==y) continue;
		parent[y] = x;
		res->push_back(to_string(x) + " " + to_string(y));
	}
	string out = joinList(*res, "\n");
	cout << res->size() << '\n';
	cout << out << "\n";
	return 0;
}
