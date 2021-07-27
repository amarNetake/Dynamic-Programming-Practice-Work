class Solution {
public:
    int minDistUtil(string word1,string word2,int m,int n,vector<vector<int>>& dp)
    {
        if(m==0) return n;
        else if(n==0) return m;
        if(dp[m][n]!=-1) return dp[m][n];
        
        if(word1[m]==word2[n]) 
        {
            dp[m][n]=minDistUtil(word1,word2,m-1,n-1,dp);
        }
        else
        {
            dp[m][n]=min({minDistUtil(word1,word2,m-1,n,dp)+1,minDistUtil(word1,word2,m,n-1,dp)+1,minDistUtil(word1,word2,m-1,n-1,dp)+1});
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        word1.insert(word1.begin(),'0');
        word2.insert(word2.begin(),'0');
        minDistUtil(word1,word2,m,n,dp);
        return dp[m][n];
    }
};