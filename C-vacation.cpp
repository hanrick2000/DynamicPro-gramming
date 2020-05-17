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

int32_t main()
{
    int n; cin >> n;
    int vec[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> vec[i][j];
    }
    int dp[n][3];
    dp[0][0] = vec[0][0];    dp[0][1] = vec[0][1];    dp[0][2] = vec[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = vec[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = vec[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = vec[i][2] + max(dp[i - 1][1], dp[i - 1][0]);
    }
    cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
}






