class Solution {
public:
    
    int numDistinctUtil(string s,string t,int i,int j,vector<vector<int>>& dp)
    {
        if(i==s.length()&& j==t.length())   return 1;
        if(i==s.length() && j<t.length()) return 0; 
        if(j==t.length()) return 1;   // Only one way that is delete all characters of s as t has exhausted.
        else if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j])
        {
            dp[i][j]= numDistinctUtil(s,t,i+1,j,dp) + numDistinctUtil(s,t,i+1,j+1,dp);
        }
        else
        {
            dp[i][j]= numDistinctUtil(s,t,i+1,j,dp);
        }
        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int count=numDistinctUtil(s,t,0,0,dp);
        return count;
    }
};