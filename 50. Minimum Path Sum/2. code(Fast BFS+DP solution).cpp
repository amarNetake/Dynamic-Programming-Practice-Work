class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)
        {
            return 0;
        }
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,false));
        pair<int,int> pa=make_pair(m-1,n-1);
        visited[m-1][n-1]=true;
        queue<pair<int,int>> q;
        q.push(pa);
        int countNodes;
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0)
            {
                break;
            }
            while(countNodes>0)
            {
                pair<int,int> curr=q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                if(i<m-1&&j<n-1)
                {
                    dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
                }
                else if(i<m-1)
                {
                    dp[i][j]=grid[i][j]+dp[i+1][j];
                }
                else if(j<n-1)
                {
                    dp[i][j]=grid[i][j]+dp[i][j+1];
                }
                else
                {
                    dp[i][j]=grid[i][j];
                }
                if(i>0&&visited[i-1][j]==false)
                {
                    q.push(make_pair(i-1,j));
                    visited[i-1][j]=true;
                }
                if(j>0&&visited[i][j-1]==false)
                {
                    q.push(make_pair(i,j-1));
                    visited[i][j-1]=true;
                }
                countNodes--;
            }
        }
        return dp[0][0];
    }
};