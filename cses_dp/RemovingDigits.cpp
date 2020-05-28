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
#define mod 1000000007c
#define setbits(x) __builtin_popcount(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define start(t) int x;cin>>x;while(x--)
#define inf LLONG_MAX
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define N 1000001

int RemovingDigits(vector<int>&dp, int number) {
    if (number == 0)    return 0;
    if (dp[number] != -1)
        return dp[number];
    int count = INT_MAX;
    string x = str(number);
    for (char ch : x) {
        int digit = ch - '0';
        if (number >= digit && digit != 0)
            count = min(count, RemovingDigits(dp, number - digit));
    }
    return dp[number] = 1 + count;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n; cin >> n;
    vector<int> dp(n + 1, -1);
    cout << RemovingDigits(dp, n) << endl;

}
