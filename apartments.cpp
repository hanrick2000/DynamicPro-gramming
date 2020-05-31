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
	int m, n, k;
	cin >> m >> n >> k;
	int desired[m];
	int size[n];
	for (int i = 0; i < m; i++)
		cin >> desired[i];
	for (int i = 0; i < n; i++) {
		cin >> size[i];
	}
	sort(size, size + m);
	sort(desired, desired + n);
	int count = 0, i = 0, j = 0;
	while (i < n && j < m) {
		if (abs(size[j] - desired[i]) <= k) {
			count += 1;
			i++; j++;
		} else if ( desired[i] < size[j] ) {
			i++;
		} else {
			j++;
		}
	}
	cout << count << endl;
}

