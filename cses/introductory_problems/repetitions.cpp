#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int counter = 1;
	int max = 1;
	string dna; cin >> dna;
	char prev = dna.at(0);
	for(int i=1; i<dna.length(); i++) {
		char c = dna.at(i);
		if(prev == c) counter++;
		else counter = 1;
		if(counter > max) max = counter;
		prev = c;
	}
	cout << max << endl;
}
