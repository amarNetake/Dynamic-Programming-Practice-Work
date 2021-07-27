int perfectSumUtility(vector<int>& nums,int n,int sum,vector<vector<int>>& dp)
	{
	    for(int i=1;i<=sum;i++)
	    {
	        if(nums[1]==i)
	        {
	            dp[1][i]=1;
	        }
	    }
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=1;
	    }
	    
	    for(int i=2;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(nums[i]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            else if(nums[i]==j)
	            {
	                dp[i][j]=1+dp[i-1][j];
	            }
	            else if(nums[i]<j)
	            {
	                dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i]];
	            }
	        }
	    }
	    return dp[n][sum];
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back(arr[i]);
        }
        nums.insert(nums.begin(),0);
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        int count=perfectSumUtility(nums,n,sum,dp);
        return count;
	}