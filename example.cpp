#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	unordered_map<int, int> um;
	for (int i = 0; i < 6; i++) {
		int x; cin >> x;
		um[x] = i;
	}
	cerr << um.size() << endl;
	for (auto p : um) {
		cerr << p.first << " " << p.second << endl;
	}

}