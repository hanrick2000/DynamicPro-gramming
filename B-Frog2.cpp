#include<bits/stdc++.h>
using namespace std;

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






int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k; cin >> n >> k;
	vector<int> h(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	h[0] = 0;
	int dp[n + 1];
	dp[1] = 0;
	dp[2] = abs(h[2] - h[1]);
	cerr << dp[1] << " " << dp[2] << endl;
	for (int i = 3; i <= n; i++) {
		int m = 1;
		int minn = INT_MAX;
		while (i - m >= 1 && m <= k) {
			if (dp[i - m] + abs(h[i] - h[i - m]) < minn)
				minn = dp[i - m] + abs(h[i] - h[i - m]);
			m++;
		}
		dp[i] = minn;
	}
	cout << dp[n] << endl;

}









