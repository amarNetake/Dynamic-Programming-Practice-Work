class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==0)  return 0;
        vector<int> dp(n);  // dp[i]=Maximum profit you can earn if you sell your stock on ith day
        //On 1st day or on 0th index we since do not have any stock in hand so we cannot sell it.So buying will put us in loss so do not buy.
        dp[0]=0;  

        //minLeft keep track of the lowest price of stock on left of current day on which we could have potentially bought the stock.
        int minLeft=prices[0]; 
        int maxProfit=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1],prices[i]-minLeft); 
            minLeft=min(minLeft,prices[i]);
            maxProfit=max(maxProfit,dp[i]);
        }
        return maxProfit;
    }
};