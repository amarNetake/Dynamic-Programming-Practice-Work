class Solution {
public:
    string LongestCommonSubseq(string str1,string str2)
    {
        int n1=str1.length();
        int n2=str2.length();
        str1.insert(str1.begin(),'0');
        str2.insert(str2.begin(),'0');
        vector<vector<string>> dp(n1+1,vector<string>(n2+1));
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0 || j==0) dp[i][j]="";
                else if(str1[i]==str2[j])
                {
                    dp[i][j]= dp[i-1][j-1] + string(1,str1[i]);
                }
                else
                {
                    dp[i][j]= (dp[i-1][j].length()>dp[i][j-1].length())?dp[i-1][j]:dp[i][j-1];
                }
            }
        }
        return dp[n1][n2];
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs=LongestCommonSubseq(str1,str2);
        int s1=0,s2=0;
        string result="";
        for(char ch: lcs)
        {
            while(s1<str1.length() && str1[s1]!=ch) 
            {
                result.insert(result.end(),str1[s1]);
                s1++;
            }
            while(s2<str2.length() && str2[s2]!=ch) 
            {
                result.insert(result.end(),str2[s2]);
                s2++;
            }
            result.insert(result.end(),ch);
            s1++;
            s2++;
        }
        while(s1<str1.length()) result.insert(result.end(),str1[s1++]);
        while(s2<str2.length()) result.insert(result.end(),str2[s2++]);
        return result;
    }
};