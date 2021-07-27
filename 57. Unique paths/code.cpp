// possible solutions:
//1.  (m-1+n-1)!/(m-1)!(n-1)!   i.e. total ways of arranging (m-1) '->' and (n-1)  'bottom arrow' 
//2.  dp[x][y]= dp[x+1][y] + dp[x][y+1] where dp[x][y] signifies the total ways to reach (m-1,n-1) from (x,y)

//O(N^2) solution
class Solution {
public:
    int uniquepathsUtil(vector<vector<int>>& dp,int x,int y,int m,int n)
    {
        if(x==m||y==n)
        {
            return 0;
        }
        if(dp[x][y]!=0)
        {
            return dp[x][y];
        }
        dp[x][y]= uniquepathsUtil(dp,x+1,y,m,n)+uniquepathsUtil(dp,x,y+1,m,n);
        return dp[x][y];
    }
    
    int uniquePaths(int m, int n)  //main() calls this
    {
       vector<vector<int>> dp(m,vector<int>(n,0));
       dp[m-1][n-1]=1;
       uniquepathsUtil(dp,0,0,m,n);
       return dp[0][0];
    }
};