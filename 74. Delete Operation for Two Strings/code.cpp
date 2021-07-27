class Solution {
public:
    int LCSubsequence(string word1,string word2)
    {
        int n1=word1.length();
        int n2=word2.length();
        word1.insert(word1.begin(),'0');
        word2.insert(word2.begin(),'0');
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(word1[i]==word2[j])
                {
                    dp[i][j]=1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]= max({dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return dp[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        int len=LCSubsequence(word1,word2);
        int l1=word1.length()-len;
        int l2=word2.length()-len;
        int result=l1+l2;
        return result;
    }
};