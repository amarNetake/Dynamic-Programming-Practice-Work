class Solution {

/* SLOW BACKTRACKING APPROACH  */

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        vector<string> dp;
        string result="";
        unordered_map<string,int> ma;
        
        for(auto x: wordDict)
        {
            ma[x]++;
        }
        backtrack(s,ma,dp,result,0,n);
        return dp;
    }
    
    void backtrack(string s,unordered_map<string,int>& ma,vector<string>& dp,string result,int curr,int n)
    {
        if(curr>=n)
        {
            dp.push_back(result);
            return;
        }
        
        for(int j=curr;j<n;j++)
        {
            string word=s.substr(curr,j-curr+1);
            if(ma.find(word)!=ma.end())
            {
                if(result.length()!=0)  
                    backtrack(s,ma,dp,result+ " "+ word,j+1,n);
                else
                    backtrack(s,ma,dp,result+ word,j+1,n);
            }
        }
        
    }
};