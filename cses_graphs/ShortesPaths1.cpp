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

vector<pair<int, int> >adj[100001];


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb(mp(y, w)); 	// one way flight.
	}

	// Priority Queue Implementation gives E.log(V) as time complexity......
	priority_queue< pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq; // minheap with comparator.....
	int dist[n + 1];
	bool flag[n + 1];
	for (int i = 1; i <= n; i++) {
		dist[i] = LLONG_MAX;
		flag[i] = false;
	}
	pq.push(mp(0, 1)); // 0 is the distance of node 1 from source (i.e node 1)
	dist[1] = 0;
	while (!pq.empty()) {
		int curr_node = pq.top().second;
		int curr_d = pq.top().first;
		pq.pop();
		flag[curr_node] = true;
		for (auto p : adj[curr_node]) {
			if ( flag[p.first] == false && curr_d + p.second < dist[p.first]) {
				dist[p.first] = curr_d + p.second;
				pq.push(mp(dist[p.first], p.first));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
}

