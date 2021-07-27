class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int w=1;w<=n;w++)
        {
            for(int i=1,j=i+w-1;j<=n;i++,j++)
            {
                if(w==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                else if(w==2)
                {
                    dp[i][j]=min(i,j);
                    continue;
                }
                int ans=INT_MAX;
                // minimax algorithm. 
                for(int k=i;k<=j;k++)
                {
                	// For luck consider the worst
                    int temp= k + max(dp[i][max(i,k-1)],dp[min(k+1,j)][j]);
                    
                    // Optimize the worst (take best among the worst)
                    ans=min(ans,temp);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }
};