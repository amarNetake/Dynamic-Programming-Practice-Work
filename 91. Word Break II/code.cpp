class Solution {
public:
    unordered_map<string,vector<string>> dp;
    
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        vector<string> result;
        if(dp.find(str)!=dp.end()) return dp[str];
        for(auto word: wordDict)
        {
            if(str.substr(0,word.length())==word)
            {
                if(str.length()==word.length()) result.push_back(word);
                else
                {
                    vector<string> temp=wordBreak(str.substr(word.length()),wordDict);
                    for(string t: temp)
                    {
                        result.push_back(word+" "+ t);
                    }
                }
            }
        }
        dp[str]=result;
        return result;
    }
};