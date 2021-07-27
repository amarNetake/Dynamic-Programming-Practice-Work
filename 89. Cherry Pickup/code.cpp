class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int r2,int c2,int c1,int n)
    {
        int r1=r2+c2-c1;
        if(r1>n-1 || r2>n-1 || c1>n-1 || c2>n-1)  return INT_MIN;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        
        if(dp[r2][c2][c1]!=-1)  return dp[r2][c2][c1];
        
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        int ans;
        ans=grid[r1][c1];
        if(c1!=c2)
        {
            ans=ans + grid[r2][c2];
        }
        int rr=dfs(grid,dp,r2+1,c2,c1,n);
        int rd=dfs(grid,dp,r2+1,c2,c1+1,n);
        int dr=dfs(grid,dp,r2,c2+1,c1,n);
        int dd=dfs(grid,dp,r2,c2+1,c1+1,n);
        ans=ans+ max({rr,rd,dr,dd});
        dp[r2][c2][c1]=ans;
        return dp[r2][c2][c1];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1)  return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        dp[0][0][0]=dfs(grid,dp,0,0,0,n);
        return dp[0][0][0]<0?0:dp[0][0][0];
    }
};