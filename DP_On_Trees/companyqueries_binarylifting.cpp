#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ff first
#define ss second
#define int long long
#define str(a) to_string(a)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SORT(c) sort(c.begin(),c.end())
#define mod 1000000007
#define max_heap priority_queue<int>
#define min_heap priority_queue<int,vi,greater<int> >
#define setbits(x) __builtin_popcount(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define start(t) int x;cin>>x;while(x--)
#define inf LLONG_MAX
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n"

const int m = 22;
const int N = 200005;
vector<int> adj[N];
int level[200005];

void dfs(int source, int par, int lev, vector<vector<int>>&sparse) {
    sparse[source][0] = par;
    level[source] = lev++;
    for (int child : adj[source]) {
        if (child != par) {
            dfs(child, source, lev, sparse);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q; cin >> n >> q;
    for (int i = 1; i <= 200001; i++)
        adj[i].clear();
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        level[i] = 1;
    }

    vector<vector<int> > sparse(n + 1, vector<int>((int)log2(n) + 1, -1));
    dfs(1, -1, 1, sparse);


    for (int j = 1; j <= (int)log2(n); j++) {
        for (int i = 1; i <= n; i++) {
            if (sparse[i][j - 1] != -1) {
                int par = sparse[i][j - 1];
                sparse[i][j] = sparse[par][j - 1];
            }
        }
    }

    while (q--) {
        int x, k; cin >> x >> k;
        while (k > 0) {
            int i = log2(k);
            x = sparse[x][i];
            if (x == -1)
                break;
            k = k - (1 << i);
        }
        cout << x << endl;
    }

}




