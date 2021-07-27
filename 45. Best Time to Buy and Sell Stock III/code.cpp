class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)  return 0;
        int leftMin=prices[0];
        int rightMax=prices[n-1];
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        leftMin=prices[0];
        rightMax=prices[n-1];
        for(int j=1;j<n;j++)
        {
            left[j]=max(left[j-1],prices[j]-leftMin);
            leftMin=min(leftMin,prices[j]);
        }
        for(int k=n-2;k>=0;k--)
        {
            right[k]=max(right[k+1],rightMax-prices[k]);
            rightMax=max(rightMax,prices[k]);
        }
        int maxProfit=0;
        for(int i=0;i<n;i++)
        {
            maxProfit=max(maxProfit,left[i]+right[i]);
        }
        
        return maxProfit;
    }
};