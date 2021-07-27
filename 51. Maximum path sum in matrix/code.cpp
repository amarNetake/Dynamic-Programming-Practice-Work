/*
    Running BFS from every node in the last row
    Time complexity:- O(n*(n-1)^2) == O(n^3)
*/
class Solution{
public:
    int maximumPath(int n, vector<vector<int>> grid)
    {
        // code here
        if(n==0)
        {
            return 0;
        }
        int maxPath=INT_MIN;
        queue<pair<int,int>> q;
        for(int x=0;x<n;x++)
        {
            vector<vector<int>> dp(grid.begin(),grid.end());
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            q.push(make_pair(n-1,x));
            visited[n-1][x]=true;
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
                    if(i<n-1&&j>0&&j<n-1)
                    {
                        dp[i][j]=grid[i][j] + max({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
                    }
                    else if(i<n-1&&j<n-1)
                    {
                        dp[i][j]=grid[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
                    }
                    else if(i<n-1&&j>0)
                    {
                        dp[i][j]=grid[i][j] + max(dp[i+1][j-1],dp[i+1][j]);
                    }
                    else
                    {
                        dp[i][j]=grid[i][j];
                    }
                    
                    if(i>0&&j>0&&visited[i-1][j-1]==false)
                    {
                        q.push(make_pair(i-1,j-1));
                        visited[i-1][j-1]=true;
                    }
                    if(i>0&&visited[i-1][j]==false)
                    {
                        q.push(make_pair(i-1,j));
                        visited[i-1][j]=true;
                    }
                    if(i>0&&j<n-1&&visited[i-1][j+1]==false)
                    {
                        q.push(make_pair(i-1,j+1));
                        visited[i-1][j+1]=true;
                    }
                    countNodes--;
                    if(i==0)
                    {
                        maxPath=max(maxPath,dp[i][j]);
                    }
                }
                
            }
        }
        return maxPath;
    }
};