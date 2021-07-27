class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n,int Path,int& minPath)
    {
        
        if(i>=m||j>=n||minPath<Path)
        {
            return;
        }
        if(i==m-1&&j==n-1)
        {
            minPath=min(minPath,Path+grid[i][j]);
            return;
        }
        dfs(grid,i+1,j,m,n,Path+grid[i][j],minPath);
        dfs(grid,i,j+1,m,n,Path+grid[i][j],minPath);
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)
        {
            return 0;
        }
        int n=grid[0].size();
        int minPath=INT_MAX;
        int Path=0;
        dfs(grid,0,0,m,n,Path,minPath);
        return minPath;
    }
};