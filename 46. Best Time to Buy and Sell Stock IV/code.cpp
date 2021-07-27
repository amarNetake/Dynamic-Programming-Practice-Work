class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<2)  return 0;
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                int Profit=0;  //Profit if k-1 transaction is done and this jth price will be concluding kth transaction
                for(int x=0;x<j;x++)
                {
                    Profit=max(Profit,dp[i-1][x]+prices[j]-prices[x]);
                }
                //If dp[i][j-1]>Profit then dp[i][j]=dp[i][j-1] implies current
                //stock price that is prices[j] was not involved in k transactions.
                dp[i][j]=max(dp[i][j-1],Profit);
            }
        }
        return dp[k][n-1];
    }
};