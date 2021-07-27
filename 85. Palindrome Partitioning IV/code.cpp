class Solution {
public:
    bool checkPartitioning(string str) {
        vector<vector<bool>> dp(str.length(),vector<bool>(str.length()));
        for(int w=1;w<=str.length();w++)
        {
            for(int i=0,j=i+w-1;j<str.length();i++,j++)
            {
                if(w==1)
                {
                    dp[i][j]=true;
                }
                else if(w==2)
                {
                    dp[i][j]= str[i]==str[j]?true:false;
                }
                else
                {
                    if(str[i]!=str[j]) dp[i][j]=false;
                    else dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        
        for(int i=0;i<str.length()-2;i++)
        {
            if(dp[0][i]==false) continue;
            for(int j=i+1;j<str.length()-1;j++)
            {
                if(dp[i+1][j]==true && dp[j+1][str.length()-1]==true) return true;
            }
        }
        return false;
    }
};