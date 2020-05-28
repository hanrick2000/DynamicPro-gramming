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


vector<int> adj[200005];

void MessageRoute(vector<bool>&vis, int source, int n) {
    int destination = n;
    queue<int> q;
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    dist[source] = 0;
    q.push(source);
    vis[source] = true;
    parent[source] = source; // this will help us to print the path later.....
    while (!q.empty()) {
        int par = q.front();
        q.pop();
        for (int neighbor : adj[par]) {
            if (vis[neighbor] == false) {
                vis[neighbor] = true;
                q.push(neighbor);
                dist[neighbor] = dist[par] + 1;
                parent[neighbor] = par;
            }
        }
    }
    if (dist[n] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] + 1 << endl;
        int d = destination;
        vector<int> path = {d};
        int count = 0;
        while (parent[d] != d) {
            int x = parent[d];
            path.pb(x);
            d = x;
        }
        reverse(path.begin(), path.end());
        for (int computer : path)
            cout << computer << " ";
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, y;
    int n, m; cin >> n >> m;
    for (int i = 0; i < 200005; i++)
        adj[i].clear();
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    MessageRoute(vis, 1, n); // source of the graph is 1.





}
