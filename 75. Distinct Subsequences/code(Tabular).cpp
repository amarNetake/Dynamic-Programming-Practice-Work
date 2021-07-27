class Solution {
public:
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        s.insert(s.begin(),'0');
        t.insert(t.begin(),'0');
        vector<vector<long long int>> dp(n1+1,vector<long long int>(n2+1,-1));
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0)
                {
                    if(j==0)  dp[i][j]=1;  //One way
                    else  dp[i][j]=0;
                    
                    continue;
                }
                if(j==0)  
                {
                    dp[i][j]=1;  //Only 1 way that is delete all characters from the string s 
                    continue;
                }
                
                if(s[i]==t[j])
                {
                    dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j]= dp[i-1][j];
                }
                
            }
        }
        return dp[n1][n2];
    }
};