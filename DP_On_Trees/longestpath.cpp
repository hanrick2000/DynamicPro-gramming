#include<bits/stdc++.h>
using namespace std;

#include<algorithm>
#define str(a) to_string(a)
#define int long long
#define pb push_back
#define N 1000001

vector<int> adj[N];
unordered_map<int, int> outdegree;
vector<int> dp;

int LongestPath(int source) {
	if (outdegree[source] == 0) {
		return dp[source] = 0;
	}
	if (dp[source] != -1)
		return dp[source];
	int mx = INT_MIN;
	for (int neighbor : adj[source]) {
		mx = max(mx, LongestPath(neighbor));
	}
	dp[source] = 1 + mx;
	return dp[source];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	dp.assign(n + 1, -1);

	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);		// Directed acyclic graph
		outdegree[x]++;
	}

	for (int i = 1; i <= n; i++) {
		if (outdegree.find(i) == outdegree.end())
			outdegree[i] = 0;
	}

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, LongestPath(i));
	}
	cout << ans << endl;


}
