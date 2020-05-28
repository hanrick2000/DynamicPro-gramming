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

void Labyrinth(int i, int j, vector<vector<bool> >&vis, vector<vector<char> >&grid, int n, int m, pair<int, int> endcord) {
    vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int> > > parent(n, vector<pair<int, int> >(m, mp(-1, -1)));
    dist[i][j] = 0; // source....
    queue<pair<int, int> > q;
    q.push(mp(i, j));
    parent[i][j] = mp(i, j);
    vis[i][j] = true;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        int p = front.first, r = front.second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = p + dx[k], ny = r + dy[k];
            if (issafe(nx, ny, n, m) && vis[nx][ny] == false && (grid[nx][ny] == '.' or grid[nx][ny] == 'B')) {
                vis[nx][ny] = true;
                q.push(mp(nx, ny));
                dist[nx][ny] = dist[p][r] + 1; // distance of the neighbor is 1+distance of parent.
                parent[nx][ny] = mp(p, r);
            }
        }

    }

    if (vis[endcord.first][endcord.second] == false) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dist[endcord.first][endcord.second] << endl;
        string path = "";
        while ( parent[endcord.first][endcord.second] != endcord ) {
            int ex = endcord.first, ey = endcord.second;
            int s = parent[ex][ey].first, t = parent[ex][ey].second;
            if (s == ex + 1 && t == ey ) {
                path += "U";
            } else if ( s == ex && t == ey + 1) {
                path += "L";
            } else if ( s == ex && t == ey - 1 ) {
                path += "R";
            } else {
                path += "D";
            }
            endcord = mp(s, t);
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    pair<int, int> end;
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'B')
                end = mp(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == false && grid[i][j] == 'A') {
                Labyrinth(i, j, vis, grid, n, m, end);
            }
        }
    }


}
