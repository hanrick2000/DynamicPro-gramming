// https://cses.fi/problemset/task/1070
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
	int n;
	cin >> n;
	vector<int> odd, even, v;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i += 2) {
		odd.pb(i);
	}
	for (int i = 2; i <= n; i += 2) {
		even.pb(i);
	}
	for (int e : even)
		v.pb(e);
	for (int i = 0; i < odd.size(); i++)
		v.pb(odd[i]);
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (abs(v[i] - v[i - 1]) <= 1) {
			flag = false;
			break;
		}
	}
	if (flag == false)
		cout << "NO SOLUTION" << endl;
	else {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}


}
