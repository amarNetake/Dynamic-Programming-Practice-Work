int perfectSumUtility(vector<int>& nums,int n,int sum,vector<vector<int>>& dp)
{
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(nums[i]>j)
            {
            	//Taking modulo as the resultant count might go out of bound of int's limit
                dp[i][j]=dp[i-1][j]%1000000007;   
            }
            else if(nums[i]==j)
            {
                //Taking modulo as the resultant count might go out of bound of int's limit
                dp[i][j]=1+dp[i-1][j]%1000000007;
            }
            else if(nums[i]<j)
            {
                //Taking modulo as the resultant count might go out of bound of int's limit
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i]])%1000000007;
            }
        }
    }
    return dp[n][sum];
}
	
int perfectSum(int arr[], int n, int sum)  //main() function calls this
{
    // Your code goes here
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        nums[i]=arr[i];
    }
    nums.insert(nums.begin(),0);
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    int  count=perfectSumUtility(nums,n,sum,dp);
    return count;
}