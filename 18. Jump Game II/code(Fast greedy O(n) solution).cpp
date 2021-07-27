int jump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=0;
        int left=0,right=1;
        while(right<n)
        {
            if(left+nums[left]>=right)
            {
                dp[right]=dp[left]+1;
                right++;
            }
            else
            {
                left++;
            }
        }
        return dp[n-1];
    }