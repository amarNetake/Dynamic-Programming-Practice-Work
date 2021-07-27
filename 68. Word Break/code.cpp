class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_map<string,int> ma;
        for(auto x: wordDict)
        {
            ma[x]++;
        }
        vector<int> dp(n+1,0); //dp[i] will say whether starting from index i can we space separate a string in words of dictionary
        
        // dp[i]=0 implies no we cannot space separate;  d[i]=1 implies we can space separate
        
        dp[n]=1;   //dp[n]=1 as nth position is the end of string 
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                string word=s.substr(i,j-i+1);
                if(ma.find(word)!=ma.end())
                {
                    if(dp[j+1]==1)
                    {
                        dp[i]=1;
                    }
                }
            }
        }
        return dp[0];
    }
};