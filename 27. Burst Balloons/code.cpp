int maxCoins(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return nums[0];
        }
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=nums[i-1]*nums[i]*nums[i+1];
        }
        
        for(int window=2;window<=n;window++)
        {
            for(int left=1,right=left+window-1;right<=n;left++,right++)
            {
                
                for(int i=left;i<=right;i++)
                {
                    if(i==left)
                    {
                        dp[left][right]=max(dp[left][right] , nums[left-1]*nums[i]*nums[right+1] + dp[i+1][right] );
                    }
                    else if(i>left && i<right)
                    {
                        dp[left][right]=max(dp[left][right] , dp[left][i-1] + nums[left-1]*nums[i]*nums[right+1] + dp[i+1][right] );
                    }
                    else if(i==right)
                    {
                        dp[left][right]=max(dp[left][right] , dp[left][i-1]+nums[left-1]*nums[i]*nums[right+1] );
                    }
                }
            }
        }
        return dp[1][n];
    }