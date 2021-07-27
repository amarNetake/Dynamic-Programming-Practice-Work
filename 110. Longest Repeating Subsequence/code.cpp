#include<bits/stdc++.h>
using namespace std;

int LCS(string str1,string str2)
{
    
    int n=str1.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                continue;
            }
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=max({dp[i-1][j],dp[i][j-1],1+dp[i-1][j-1]});
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    string str;
    cin>>str;
    int result=LCS(str,str);
    cout<<result<<"\n";
}