class Solution {
public:
    int solve(vector<int>& dp,unordered_map<int,int>& ma,int largest)
    {
        int maxPoints=0;
        for(int i=1;i<=largest;i++)
        {
            if(ma.find(i)==ma.end())
            {
                dp[i]=dp[i-1];
                maxPoints=max(maxPoints,dp[i]);
            }
            else
            {
                if(i!=1) dp[i]=max(dp[i-1],dp[i-2]+ma[i]*i);
                else dp[i]=ma[i]*i;
                maxPoints=max(maxPoints,dp[i]);
            }
        }
        return maxPoints;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> ma;
        int largest=INT_MIN;
        for(auto x: nums)
        {
            ma[x]++;
            largest=max(largest,x);
        }
        vector<int> dp(largest+1,0);
        int maxPoints=0;
        maxPoints=solve(dp,ma,largest);
        return maxPoints;
    }
};