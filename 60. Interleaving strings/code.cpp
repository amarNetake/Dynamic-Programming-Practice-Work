class Solution {
public:
    
    bool interleaveUtil(string str1,string str2,string str3,int len1,int len2,int len3,int p1,int p2,int p3,unordered_map<string,bool>& dp)
    {
        if(p3==len3)
        {
            return (p1==len1 && p2==len2)?true:false;
        }
        string key= to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }
        if(p1==len1)
        {
            dp[key]= (str2[p2]==str3[p3])?interleaveUtil(str1,str2,str3,len1,len2,len3,p1,p2+1,p3+1,dp):false;
            return dp[key];
        }
        if(p2==len2)
        {
            dp[key]= (str1[p1]==str3[p3])?interleaveUtil(str1,str2,str3,len1,len2,len3,p1+1,p2,p3+1,dp):false;
            return dp[key];
        }
        bool first=false,second=false;
        first= (str2[p2]==str3[p3])?interleaveUtil(str1,str2,str3,len1,len2,len3,p1,p2+1,p3+1,dp):false;
        second= (str1[p1]==str3[p3])?interleaveUtil(str1,str2,str3,len1,len2,len3,p1+1,p2,p3+1,dp):false;
        
        dp[key]= first or second;
        return dp[key];
    }
    
    bool isInterleave(string str1, string str2, string str3) 
    {
        int len1=str1.length();
        int len2=str2.length();
        int len3=str3.length();
        if(len1+len2==len3 && len3==0) return true;
        if(len1+len2!=len3)  return false;
        unordered_map<string,bool> dp;
        interleaveUtil(str1,str2,str3,len1,len2,len3,0,0,0,dp);
        
        return dp["0*0*0"];
    }
};