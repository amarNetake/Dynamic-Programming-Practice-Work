class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = min coins to make up to amount i
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins) //We will scan for each coin in outer loop to avoid redundancy in checking for cases when coins[i] > currAmount
        {
        	//That particular 'coin' will satisfy the amount that is greater than or equal to 'coin' itself. This is avoiding redundancy
            for (int i = coin; i <= amount; ++i)
                if (dp[i - coin] != INT_MAX)  
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};