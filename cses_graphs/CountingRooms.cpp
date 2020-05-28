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


int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool issafe(int i, int j, int n, int m) {
    if ( i >= 0 && j < m && i < n && j >= 0 )
        return true;
    return false;
}
void CountingRooms(vector<vector<bool> >&vis, vector<vector<char> >&grid, int i, int j, int n, int m) {
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
        if (issafe(i + dx[k], j + dy[k], n, m) && vis[i + dx[k]][j + dy[k]] == false && grid[i + dx[k]][j + dy[k]] == '.') {
            CountingRooms(vis, grid, i + dx[k], j + dy[k], n, m);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == false && grid[i][j] == '.') {
                CountingRooms(vis, grid, i, j, n, m);
                count += 1;
            }
        }
    }
    cout << count << endl;


}
