// Using coin change variation
int numSquares(int n) {
        
        vector<vector<int>> dp(10000,vector<int>(n+1,-1));
        int minSoFar= INT_MAX;
        
        for(int i=0;i*i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                {
                    dp[i][j]=0;
                }
                else if(i==0)
                {
                    dp[i][j]=-1;
                }
                else
                {
                    if(i*i>n)
                    {
                        return minSoFar;
                    }
                    else if(i*i==j)
                    {
                        dp[i][j]=1;
                    }
                    else if(i*i>j)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else if(i*i<j)
                    {
                        if(dp[i-1][j]!=-1 && dp[i][j-i*i]!=-1)
                        {
                            dp[i][j]=min(dp[i-1][j],1 + dp[i][j-i*i]);
                        }
                        else if(dp[i-1][j]==-1 && dp[i][j-i*i]!=-1)
                        {
                            dp[i][j]= 1 + dp[i][j-i*i];
                        }
                        else if(dp[i-1][j]!=-1 && dp[i][j-i*i]==-1)
                        {
                            dp[i][j]=dp[i-1][j];
                        }
                        else
                        {
                            dp[i][j]=-1;
                        }
                    }
                }
                if(j==n && i!=0)
                {
                    minSoFar=min(minSoFar,dp[i][j]);
                }
            }
        }
        return minSoFar;
    }