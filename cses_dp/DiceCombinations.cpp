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

int NumberOfWays(int n,vector<int>&dp){
    if(n==0)    return 1;
    int count=0;
    if(dp[n]!=-1)
        return dp[n];
    for(int dice=1;dice<=6;dice++){
        if(dice<=n){
            if(dp[n-dice]!=-1)
                count=(count%mod+dp[n-dice]%mod)%mod;
            else
                count=(count%mod+NumberOfWays(n-dice,dp)%mod)%mod;
        }
    }
    return dp[n]=count;
}

//int NumberofWaysBottomUp()

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<int> dp(n+1,-1);
    cout<<NumberOfWays(n,dp)<<endl;
    
}

