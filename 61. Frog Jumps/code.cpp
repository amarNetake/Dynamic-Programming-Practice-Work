class Solution {
public:
    bool crossUtil(vector<int>& stones,unordered_map<int,int>&ma,unordered_map<string,bool>& dp,int curr,int jump,int last)
    {
        if(curr==last)  return true;
        if(jump<0) return false;
        string key=to_string(curr)+"*"+to_string(jump);
        if(dp.find(key)!=dp.end()) return dp[key];
        
        bool first=false,second=false,third=false;
        first=(ma.find(curr+jump-1)!=ma.end() && jump>=0)?crossUtil(stones,ma,dp,curr+jump-1,jump-1,last):false;
        second=(ma.find(curr+jump)!=ma.end() && jump>0)?crossUtil(stones,ma,dp,curr+jump,jump,last):false;
        third=(ma.find(curr+jump+1)!=ma.end()&& jump>=0)?crossUtil(stones,ma,dp,curr+jump+1,jump+1,last):false;
        dp[key]=first or second or third;
        return dp[key];
    }
    bool canCross(vector<int>& stones) {
        int curr=0;
        int jump=0;
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            if(stones[i]>curr+jump)   return false;
            curr=curr+jump;
            jump=jump+1;
        }
        unordered_map<int,int> ma;
        for(int i=0;i<stones.size();i++)
        {
            ma[stones[i]]=i;
        }
        int last=stones[n-1];
        unordered_map<string,bool> dp;
        crossUtil(stones,ma,dp,0,0,last);
        return dp["0*0"];
    }
};