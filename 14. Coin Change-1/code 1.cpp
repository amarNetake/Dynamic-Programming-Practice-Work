int coinChange(vector<int>& coins, int A) 
{    
    if(A==0)
    {
        return 0;
    }
    int C=coins.size();
    coins.insert(coins.begin(),0);
    vector<vector<int>> dp(C+1,vector<int>(A+1,-1));
    for(int i=0;i<=C;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=C;i++)
    {
        for(int j=1;j<=A;j++)
        {
            if(coins[i]==j)
            {
                dp[i][j]=1;
            }
            else if(coins[i]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(coins[i]<j)
            {
                if(dp[i-1][j]!=-1&&dp[i][j-coins[i]]!=-1)
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
                }
                else if(dp[i-1][j]==-1&&dp[i][j-coins[i]]!=-1)
                {
                    dp[i][j]= dp[i][j-coins[i]]+1;
                }
                else if(dp[i][j-coins[i]]==-1)
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    
    return dp[C][A];
}