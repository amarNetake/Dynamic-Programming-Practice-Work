// O(N^2) solution
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
        vector<int> result(n);
        result[0]=0;
        for(int i=1;i<n;i++)
        {
            int cuts,minCuts=INT_MAX;
            if(dp[0][i]==true) result[i]=0;
            else
            {
                for(int j=i;j>=1;j--)
                {
                    if(dp[j][i]==true)
                    {
                        cuts=result[j-1]+1;
                        minCuts=min(minCuts,cuts);
                    }
                }
                result[i]=minCuts;
            }
        }
        return result[n-1];
    }
};