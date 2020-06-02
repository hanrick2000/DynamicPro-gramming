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


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a, b; cin >> a >> b;
	int n = a.length(), m = b.length();
	vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
	for (int i = 0; i <= n; i++)
		dp[i][0] = i;
	for (int i = 0; i <= m; i++)
		dp[0][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int remove = 1 + dp[i][j - 1];
			int insert = 1 + dp[i - 1][j];
			int modify = INT_MAX, letgo = INT_MAX;
			if (a[i - 1] == b[j - 1])	letgo = dp[i - 1][j - 1];
			else	modify = 1 + dp[i - 1][j - 1];
			dp[i][j] = min(remove, min(min(modify, letgo), insert));
		}
	}
	cout << dp[n][m] << endl;
}

