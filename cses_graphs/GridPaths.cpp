#include<bits/stdc++.h>
using namespace std;

#include<algorithm>
#define str(a) to_string(a)
#define int long long
#define pb push_back
#define mp make_pair
#define SORT(c) sort(c.begin(),c.end())
#define max_heap priority_queue<int>
#define min_heap priority_queue< int,vector<int>, greater<int> >
#define mod 1000000007
#define setbits(x) __builtin_popcount(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define start(t) int x;cin>>x;while(x--)
#define inf LLONG_MAX
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define N 1000001

int FindPaths(vector<vector<char> >&grid, int n) {
	if (grid[n - 1][n - 1] == '*')
		return 0;  // no path ......
	vector<vector<int> > dp(n, vector<int>(n, 0));
	bool blocked = false;
	for (int i = n - 1; i >= 0; i-- ) {
		if (grid[i][n - 1] == '*') {
			blocked = true;
			dp[i][n - 1] = 0;
		} else if (blocked == true) {
			dp[i][n - 1] = 0;
		} else {
			dp[i][n - 1] = 1;
		}
	}
	blocked = false;
	for (int i = n - 1; i >= 0; i-- ) {
		if (grid[n - 1][i] == '*') {
			blocked = true;
			dp[n - 1][i] = 0;
		} else if (blocked == true) {
			dp[n - 1][i] = 0;
		} else {
			dp[n - 1][i] = 1;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			if (grid[i][j] == '*')
				dp[i][j] = 0;
			else {
				int right = (grid[i][j + 1] == '*') ? 0 : dp[i][j + 1];
				int down = (grid[i + 1][j] == '*') ? 0 : dp[i + 1][j];
				dp[i][j] = (right % mod + down % mod) % mod;
			}
		}
	}
	return dp[0][0];
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<vector<char> > grid(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	cout << FindPaths(grid, n) << endl;

}
