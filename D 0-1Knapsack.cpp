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


int MaximumProfit(vector<int>& w, vector<int>& p, int idx, int n, int remcap) {
	if (idx >= n)
		return 0;
	if (w[idx] > remcap) {
		return MaximumProfit(w, p, idx + 1, n, remcap);  // this was important....
	}
	return max(p[idx] + MaximumProfit(w, p, idx + 1, n, remcap - w[idx]), MaximumProfit(w, p, idx + 1, n, remcap));
}

int MemoisedDP(vector<int>& w, vector<int>& p, int idx, int n, int remcap, vector<vector<int> >&dp) {
	if (idx >= n)
		return 0;
	if (dp[idx][remcap] != -1) {
		return dp[idx][remcap];
	}
	if (w[idx] > remcap) {
		return dp[idx][remcap] = MemoisedDP(w, p, idx + 1, n, remcap, dp); // this was important....
	}
	return dp[idx][remcap] = max(p[idx] + MemoisedDP(w, p, idx + 1, n, remcap - w[idx], dp), MemoisedDP(w, p, idx + 1, n, remcap, dp));
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
	int n, k;
	cin >> n >> k;
	vector<int> weight(n);
	vector<int> prices(n);
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> prices[i];
	}
	int cap = k;
	vector<vector<int> > knapsack(n, vector<int>(cap + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= cap; j++)
			knapsack[i][j] = -1;
	}

	// cout << MaximumProfit(weight, prices, 0, n, k) << endl;
	cout << MemoisedDP(weight, prices, 0, n, k, knapsack) << endl;

}










