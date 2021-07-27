class Solution {
public:
    int LCS(string str1,string str2,int n1,int n2,vector<vector<int>>& dp)
    {
        if(n1==-1||n2==-1)
        {
            return 0;
        }
        if(dp[n1][n2]!=-1)
        {
            return dp[i][j];
        }
        
        if(str1[n1]==str2[n2])
        {
            dp[n1][n2]=1 + LCS(str1,str2,n1-1,n2-1,dp);
        }
        else
        {
            dp[n1][n2]=max(LCS(str1,str2,n1-1,n2,dp), LCS(str1,str2,n1,n2-1,dp));
        }
        return dp[n1][n2];
    }
    
    int longestCommonSubsequence(string str1, string str2) //main() calls this
    {
        
        int n1=str1.length();
        int n2=str2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int maxLen;
        maxLen=LCS(str1,str2,n1-1,n2-1,dp);
        return maxLen;
    }
};