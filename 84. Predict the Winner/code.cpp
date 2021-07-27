class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int w=1;w<=n;w++)
        {
            for(int i=0,j=i+w-1;j<n;i++,j++)
            {
                if(w==1) dp[i][j]=nums[i];
                else if(w==2) dp[i][j]=max(nums[i],nums[j]);
                else
                {
                    int event1=nums[i] + min(dp[i+1][j-1],dp[i+2][j]);
                    int event2=nums[j] + min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j]=max(event1,event2);
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+ nums[i];
        }
        if(dp[0][n-1]>=sum-dp[0][n-1]) return true;
        return false;
    }
};