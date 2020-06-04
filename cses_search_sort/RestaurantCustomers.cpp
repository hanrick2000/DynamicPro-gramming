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
	int n; cin >> n;
	vector<int> A, B;
	while (n--) {
		int x, y; cin >> x >> y;
		A.pb(x);
		B.pb(y);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int maxx = INT_MIN, count = 0;
	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] < B[j]) {
			count += 1;
			if (maxx < count)
				maxx = count;
			i++;
		} else if (A[i] > B[i]) {
			count--;
			if (maxx < count)
				maxx = count;
			j++;
		} else {
			i++; j++;
		}
	}
	while (i < A.size()) {
		count += 1;
		if (maxx < count)
			maxx = count;
		i++;
	}
	while (j < B.size()) {
		count -= 1;
		if (maxx < count)
			maxx = count;
		j++;
	}
	cout << maxx << endl;

}