class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        //dp[i] will store the difference of curr player - opponent player . 
        //If A and B are players and A is playing from index i onwards dp[i] will store scoreA-scoreB for the array from index i to n-1
        vector<int> dp(n+3,-1e8); //Added 3 to avoid array to go out of bound
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int sum=0;
            for(int j=i;j<=i+2&&j<n;j++)
            {
                sum=sum+stoneValue[j];
                dp[i]=max(dp[i],sum-dp[j+1]);
            }
        }
        if(dp[0]>0) return "Alice";
        else if(dp[0]==0) return "Tie";
        else return "Bob";
    }
};