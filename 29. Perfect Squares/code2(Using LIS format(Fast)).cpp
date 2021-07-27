// Variant of Longest Increasing Subsequence
int numSquares(int n) {
        
        vector<int> dp(n+1,INT_MAX);  //dp[i] will hold the best minimum perfect squares count to generate sum i
        
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                int result= 1 + dp[i-j*j];  
                dp[i]=min(dp[i],result);
            }
        }
        return dp[n];
    }