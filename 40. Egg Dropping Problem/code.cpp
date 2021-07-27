#include <bits/stdc++.h>
using namespace std;

int EggDropUtil(vector<vector<int>>& dp,int n,int e)
{
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=e;j++)
        {
            dp[i][j]=INT_MAX;
            for(int x=1;x<i;x++)
            {
                dp[i][j]=min(dp[i][j],max(dp[x-1][j-1]+1,dp[i-x][j]+1));
            }
        }
    }
    return dp[n][e];
}

int EggDropOptimal(int n,int e)
{
    if(n<=1)
    {
        return 1;
    }
    if(e<=1)
    {
        return n;
    }
    vector<vector<int>> dp(n+1,vector<int>(e+1,0));
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=i;
    }
    for(int i=1;i<=e;i++)
    {
        dp[1][i]=1;
    }
    int result=EggDropUtil(dp,n,e);
    return result;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,e;
	    cin>>e>>n;
	    int count=EggDropOptimal(n,e);
	    cout<<count<<"\n";
	}
	return 0;
}