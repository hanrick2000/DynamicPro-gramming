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



int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int h, w; cin >> h >> w;
	vector<vector<char> > grid(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cin >> grid[i][j];
	}
	int dp[h][w];  // dp[i][j] means number of paths from i,j to h,w
	dp[h - 1][w - 1] = 1;  // an empty path.
	for (int i = h - 2; i >= 0 ; i--) {
		if (grid[i][w - 1] == '#')
			dp[i][w - 1] = 0;
		else dp[i][w - 1] = dp[i + 1][w - 1];
	}
	for (int i = w - 2; i >= 0 ; i--) {
		if (grid[h - 1][i] == '#')
			dp[h - 1][i] = 0;
		else dp[h - 1][i] = dp[h - 1][i + 1];
	}
	for (int i = h - 2; i >= 0; i--) {
		for (int j = w - 2; j >= 0; j--) {
			if (grid[i][j] == '#')
				dp[i][j] = 0;
			else {
				dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % 1000000007;
			}
		}

	}
	cout << dp[0][0] << endl;

}








