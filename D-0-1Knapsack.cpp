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


int ZeroOneKnapsack(vector<int>&weights, vector<int>&profits, int  index, int n, int capacity, vector<vector<int> >&memo) {

	// cout << "(weights,profits, " << index << ", " << n << ", " << capacity << ")" << endl;

	if (index >= n || capacity <= 0) {
		return 0;
	}
	if (memo[index][capacity] != -1)
		return memo[index][capacity];

	// two options...take it or not take it.
	int take = 0;
	if (weights[index] <= capacity )
		take += profits[index] + ZeroOneKnapsack(weights, profits, index + 1, n, capacity - weights[index], memo);
	int leave = ZeroOneKnapsack(weights, profits, index + 1, n, capacity, memo);
	return memo[index][capacity] = max(take, leave);
}

int ZeroOneKnapsackBottomUp(vector<int>&weights, vector<int>&profits, int n, int capacity ) {
	vector<vector<int> > dp(n, vector<int>(capacity + 1, 0));
	vector<int> itemstaken;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= capacity; j++) {
			if (i == 0 ) {
				if (weights[0] <= j) {
					dp[0][j] = profits[i];
				}
			} else {
				int take = INT_MIN ;
				if (weights[i] <= j)
					take = profits[i] + dp[i - 1][j - weights[i]];
				int leave = dp[i - 1][j];
				dp[i][j] = max(take, leave);
			}
		}
	}
	// items selected.....
	int finalans = dp[n - 1][capacity];
	int result = dp[n - 1][capacity];
	for (int i = n - 1; i > 0; i--) {
		if (finalans != dp[i - 1][capacity]) {
			itemstaken.pb(i + 1);
			capacity = capacity - weights[i];
			finalans = finalans - profits[i];
		}
	}
	if (finalans != 0)
		itemstaken.pb(1);
	for (int items : itemstaken) {
		cout << items << " ";
	}
	cout << endl;

	return result;
}

int SpaceOptimizedBottomUp(vector<int>&weights, vector<int>&profits, int n, int capacity ) {
	int dp[2][capacity + 1];
	for (int i = 0; i <= capacity; i++) {
		dp[0][i] = 0;
		dp[1][i] = 0;
	}
	for (int i = 0; i <= capacity; i++) {
		if (weights[0] <= i)
			dp[0][i] = dp[1][i] = profits[0];
	}
	for (int i = 1; i < n; i++) {
		for (int c = 1; c <= capacity; c++) {
			int take = INT_MIN, skip;
			if (weights[i % 2] <= c)
				take = profits[i] + dp[(i - 1) % 2][c - weights[i]];
			skip = dp[(i - 1) % 2][c];
			dp[i % 2][c] = max(take, skip);
		}
	}
	return dp[(n - 1) % 2][capacity];
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
	int n, x, y, c; cin >> n >> c;
	vector<int> weights, profits;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		weights.pb(x); profits.pb(y);
	}
	// vector<vector<int> > memo(n, vector<int>(c + 1, -1));
	// cout << ZeroOneKnapsack(weights, profits, 0, n, c, memo) << endl;
	cout << ZeroOneKnapsackBottomUp(weights, profits, n, c) << endl;
	cout << SpaceOptimizedBottomUp(weights, profits, n, c) << endl;


}






