
#include<bits/stdc++.h>
#include<algorithm>
#define str(a) to_string(a)
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
#define endl "\n"
using namespace std;

std::vector<int> adj[100001];
int in[100001];		 // height of the subtree rooted at i;
int out[100001];	 // height of the tree neglecting the subtree rooted at i.

void dfs1(int source, int par) {
	in[source] = 0;
	for (int child : adj[source]) {
		if (child == par)
			continue;
		dfs1(child, source);
		in[source] = max(in[source], 1 + in[child]);
	}
}

void dfs2(int source, int par) {

	int mx1 = -1, mx2 = -1;
	for (int x : adj[source]) {
		if (x == par) continue;
		if (in[x] > mx1) {
			mx2 = mx1;
			mx1 = in[x];
		} else if (in[x] > mx2) mx2 = in[x];
	}
	// child will know the out of their parent....no need to worry.
	for (int v : adj[source]) {
		if (v == par) continue;
		int use = mx1;
		if (mx1 == in[v])	use = mx2;
		out[v] = max(1 + out[source], 2 + use);
		dfs2(v, source);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		ans[i] = max(in[i], out[i]);
	}


}
