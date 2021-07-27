int maximalSquare(vector<vector<char>>& matrix) 
{
        
    int rows=matrix.size();
    if(rows==0||matrix[0].empty()==true)
    {
        return 0;
    }
    int cols=matrix[0].size();
    
    vector<vector<int>> dp(rows,vector<int>(cols));
    int answer=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j]=='1')
            {
                dp[i][j]=1;
                if(i>0&&j>0)
                {
                    dp[i][j]=dp[i][j] + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                answer=max(answer,dp[i][j]);
            }
        }
    }
    return answer * answer;
}