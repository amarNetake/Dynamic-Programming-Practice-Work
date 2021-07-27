long long maximumAmount(int vect[], int n) 
{
    // Your code here
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int w=1;w<=n;w++)
    {
        for(int i=0;i+w-1<n;i++)
        {
            int start=i;
            int end=i+w-1;
            if(w==1)
            {
                dp[start][end]=vect[start];
            }
            else if(w==2)
            {
                dp[start][end]=max(vect[start],vect[end]);
            }
            else
            {
                int x= vect[start] + min(dp[start+2][end],dp[start+1][end-1]);
                int y= vect[end] + min(dp[start+1][end-1],dp[start][end-2]);
                dp[start][end]=max(x,y);
            }
        }
    }
    return dp[0][n-1];
}