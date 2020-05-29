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

bool CanBuildTeam(vector<bool>&vis, int n, int source, int team, vector<int>&teams) {
    teams[source] = team; // source assiged a team.....
    vis[source] = true;
    for (int neighbor : adj[source]) {
        if (vis[neighbor] == false) {
            if (CanBuildTeam(vis, n, neighbor, team ^ 1, teams) == false)
                return false;
        }
        if (teams[neighbor] == team) {
            return false;       // if at any moment friends have same team , just return false.
        }
    }
    return true;
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
    vector<int> teams(n + 1, -1);   // initially no team assigned.....
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            if (CanBuildTeam(vis, n, i, 0, teams) == false) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << teams[i] + 1 << endl;
    }


}
