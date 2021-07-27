class Solution {
public:
    int countSubstrings(string str) {
        vector<vector<int>> dp(str.length(),vector<int>(str.length(),0));
        int count=0;
        for(int w=1;w<=str.length();w++)
        {
            for(int s=0,e=s+w-1;e<str.length();s++,e++)
            {
                if(w==1)
                {
                    count++;
                    dp[s][e]=1;
                }
                else if(w==2 && str[s]==str[e])
                {
                    dp[s][e]=1;
                    count++;
                }
                else if(str[s]==str[e] && dp[s+1][e-1]==1)
                {
                    dp[s][e]=1;
                    count++;
                }
            }
        }
        return count;
    }
};