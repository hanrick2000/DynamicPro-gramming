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
	int n;
	cin >> n;
	vector<double> p(n + 1);
	for (int i = 1; i <= n; i++)	cin >> p[i];
	double dp[n + 1][ ((n + 1) / 2) + 1 ];
	dp[1][1] = p[1];
	double prod = 1;
	for (int i = 2; i <= n; i++) {
		dp[1][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= (n + 1) / 2; j++) {
			dp[i][j] = (p[i] * (dp[i - 1][j - 1])) + (1 - p[i]) * (dp[i - 1][j]);
			// cerr << "(" << i << "," << j << ") " << dp[i][j] << endl;
		}
	}
	cout << fixed << setprecision(10) << dp[n][(n + 1) / 2] << endl;

}








