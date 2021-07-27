int change(int amount, vector<int>& coins) {
        if(amount==0)
        {
            return 1;
        }
        int n=coins.size();
        coins.insert(coins.begin(),0); //Inserted denomination 0 in the beginning
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));  //initialized number of ways to generate as any amount as 0.
        for(int i=0;i<=n;i++)          
        {
            dp[i][0]=1;   //Initialized the number of ways to generate amount 0 for any number of coins available as 1
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(coins[i]==j)
                {
                    dp[i][j]=dp[i-1][j] + 1;
                }
                else if(coins[i]<j)
                {
                    dp[i][j]=dp[i-1][j] + dp[i][j-coins[i]];  // We can include this coin or can exclude
                }
            }
        }
        return dp[n][amount];
    }