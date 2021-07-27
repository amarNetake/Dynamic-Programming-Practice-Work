class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,INT_MAX);
        
        dp[0]=0;
        for(int currAmount=1;currAmount<=amount;currAmount++)
        {
            for(int x:coins)
            {
                if(x<=currAmount && dp[currAmount-x]!=INT_MAX)
                {
                    dp[currAmount]=min(dp[currAmount], 1 + dp[currAmount-x]);
                }
            }
        }
        if(dp[amount]==INT_MAX)  return -1;
        
        return dp[amount];
    }
};