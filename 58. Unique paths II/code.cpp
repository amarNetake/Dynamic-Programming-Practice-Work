class Solution {
public:
    int pathUtil(vector<vector<int>>& obstacle,vector<vector<int>>& dp,int x,int y,int m,int n)
    {
        if(x==m||y==n||obstacle[x][y]==1)
        {
            return 0;
        }
        else if(dp[x][y]!=0)
        {
            return dp[x][y];
        }
        dp[x][y]= pathUtil(obstacle,dp,x+1,y,m,n)+ pathUtil(obstacle,dp,x,y+1,m,n);
        return dp[x][y];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m=obstacle.size();
        int n=obstacle[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacle[m-1][n-1]==1) //No way to reach target
        {
            return 0;
        }
        dp[m-1][n-1]=1;  //Target can be reached by itself in 1 way
        pathUtil(obstacle,dp,0,0,m,n);
        return dp[0][0];
    }
};