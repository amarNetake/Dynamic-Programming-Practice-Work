// O(N^3) solution
class Solution {
public:
    int minCut(string str) {
        int n=str.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int w=1;w<=n;w++)
        {
            for(int i=0,j=i+w-1;j<n;i++,j++)
            {
                if(w==1)   dp[i][j]=true;
                else if(w==2)    dp[i][j]=str[i]==str[j]?true:false;
                else 
                {
                    if(str[i]!=str[j]) dp[i][j]=false;
                    else dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        vector<vector<int>> result(n,vector<int>(n,INT_MAX));
        for(int w=1;w<=n;w++)
        {
            for(int i=0,j=i+w-1;j<n;i++,j++)
            {
                if(w==1) result[i][j]=0;
                else if(w==2)
                {
                    if(dp[i][j]==true) result[i][j]=0;
                    else result[i][j]=1;
                }
                else
                {
                    if(dp[i][j]==true)
                    {
                        result[i][j]=0;
                        continue;
                    }
                    for(int k=i;k<j;k++)
                    {
                        result[i][j]=min(result[i][j],result[i][k]+result[k+1][j]+1);
                    }
                }
            }
        }
        
        return result[0][n-1];
    }
};