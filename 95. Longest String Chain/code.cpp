// Works similar on the principle of LIS

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<pair<int,string>> shabd;
        for(auto word:words) shabd.push_back({word.length(),word});
        sort(shabd.begin(),shabd.end()); //Sorted based on increasing string length
        unordered_map<string,int> ma;
        vector<bool> mapped(16,false);
        for(auto word: words) 
        {
            ma[word]=1;
            mapped[word.length()]=true;  //To keep track if word of particular length exists or not
        }
        int maxCount=1;
        for(auto x: shabd)
        {
            string word=x.second;
            //If the word of length one smaller than current word exist then it is possible that this 
            //this current word can be appended to form longest length sequence else if no such word exist
            // of length one smaller than current word then simply continue.
            if(mapped[word.length()-1]==false|| word.length()==1) continue;
            for(int i=0;i<word.length();i++)
            {
                string str=word.substr(0,i)+word.substr(i+1);  
                if(ma.find(str)!=ma.end())
                {
                    ma[word]=max(ma[word],ma[str]+1);
                    //break;
                }
            }
        }
        
        for(auto x: ma) maxCount=max(maxCount,x.second);
        return maxCount;
    }
};