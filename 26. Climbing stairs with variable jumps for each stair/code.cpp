#include<bits/stdc++.h>
using namespace std;

int countWays(int n,vector<int>& jumps)
{
    vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=jumps[i] && i+j<=n;j++)
        {
            dp[i]=dp[i]+dp[i+j];
        }
    }
    return dp[0];
}

int main()
{
    int n;
    cin>>n;
    vector<int> jumps(n);
    for(auto& it: jumps)
    {
        cin>>it;
    }
    int ways=countWays(n,jumps);
    cout<<ways;
}