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

void dfs(vector<bool>&vis, int source) {
    vis[source] = true;
    for (int neighbor : adj[source]) {
        if (vis[neighbor] == false) {
            dfs(vis, neighbor);
        }
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
    vector<int> connected_component; // it contains the first element of a connected component.
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            connected_component.pb(i);
            dfs(vis, i);
            count += 1;
        }
    }
    cout << count - 1 << endl;
    for (int i = 0; i < count - 1; i++) {
        cout << connected_component[i] << " " << connected_component[i + 1] << endl;
    }




}
