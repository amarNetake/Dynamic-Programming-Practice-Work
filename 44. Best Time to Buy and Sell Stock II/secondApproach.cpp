class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int totalProfit=0;
        int b=0,s=0;  // b => bought ;  s => sold
        for(int i=0;i<n;i++)
        {
            if(i<n-1 && prices[i]<=prices[i+1])
            {
                s++;
            }
            else
            {
                totalProfit=totalProfit + (prices[s]-prices[b]);
                b=s+1;
                s=s+1;
            }
        }
        return totalProfit;
    }
};