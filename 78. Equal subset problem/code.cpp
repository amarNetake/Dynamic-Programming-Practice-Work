bool isPossible(vector<int> vect,vector<vector<bool>> dp,int n,int total)
{
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=total;j++)
        {
            if(dp[i-1][j]==true||(j>=vect[i] && dp[i-1][j-vect[i]]==true)) //Never forget to check j>=vect[i] to avoid segmentation error
            {
                dp[i][j]=true;
                if(j==total/2)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int equalPartition(int n, int arr[]) //main() calls this function
{
    // code here
    if(n==0)
    {
        return true;
    }
    vector<int> vect(arr,arr+n);
    
    int total=0;
    for(int x: vect)
    {
        total+=x;
    }
    if(total%2==1||total==0)
    {
        return false;
    }
    
    vect.insert(vect.begin(),0);
    vector<vector<bool>> dp(n+1,vector<bool>(total+1,false));
    return isPossible(vect,dp,n,total);
}