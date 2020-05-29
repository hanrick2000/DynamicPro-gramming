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

vector<int> adj[100001];
// To store the starting point of cycle. This is done to print the cities found in a ound trip
vector<int> cyclefoundat;

// a traditional cycle detection using dfs by finding the presence of any backedge.
bool RoundTripPossibleOrNot(vector<bool>&vis, int source, int par, vector<int>&parent) {
	vis[source] = true;	// marking the source as visited.
	parent[source] = par; // upadating parent of the node.
	for (int neighbor : adj[source]) {
		if (vis[neighbor] == false) {
			if (RoundTripPossibleOrNot(vis, neighbor, source, parent) == true) {
				return true;
			}
		}
		else if (par != neighbor) {		// Found the backedge......hence the presence of a cycle.
			cyclefoundat.pb(neighbor);		//store the cycle's starting point........
			parent[neighbor] = source;
			return true;
		}
	}
	return false;
}

// Printing the cities found in any round trip.....
void printcities(vector<int>&parent) {
	// we do not need to check if this vector is empty or not.(It will always contain atleat one element)
	int i = cyclefoundat[0];
	int x = i;
	vector<int> CitiesInRoundTrip = {x};
	int par = parent[i];
	while (par != i) {
		CitiesInRoundTrip.pb(par);
		par = parent[par];
	}
	CitiesInRoundTrip.pb(i);
	cout << CitiesInRoundTrip.size() << endl;
	for (int x : CitiesInRoundTrip) {
		cout << x << " ";
	}
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	for (int i = 0; i <= 100001; i++)
		adj[i].clear();
	cyclefoundat.clear();
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vector<int> parent(n + 1, -1);	// to keep the track of parent of each node to print the ans.....
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			bool cond = RoundTripPossibleOrNot(vis, i, -1, parent);
			if (cond == true) {
				printcities(parent);
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl; 	// if round trip would have been there.....the program would have already terminated above.
}

