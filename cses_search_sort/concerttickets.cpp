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
	int n, m; cin >> n >> m;
	multiset<int, greater<int> > concert_tickets;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		concert_tickets.insert(x);
	}
	while (m--) {
		int x; cin >> x;
		auto itr = concert_tickets.lower_bound(x);
		if (itr == concert_tickets.end()) {
			cout << "-1" << endl;
		} else {
			cout << *itr << endl;
			concert_tickets.erase(itr);
		}
	}

}

