//Using stone game approach - Time complexity-O(n^2) slow

class Solution {
public:
    int solve(vector<int>& cardPoints,unordered_map<int,unordered_map<int,unordered_map<int,int>>>& ma,int k,int s,int e)
    {
        if(k==0) 
        {
            return 0;
        }
        if(ma.find(s)!=ma.end())
        {
            if(ma[s].find(e)!=ma[s].end())
            {
                if(ma[s][e].find(k)!=ma[s][e].end()) return ma[s][e][k];
            }
        }
        
        int temp1=solve(cardPoints,ma,k-1,s+1,e)+cardPoints[s];
        int temp2=solve(cardPoints,ma,k-1,s,e-1)+cardPoints[e];
        
        ma[s][e][k]=max(temp1,temp2);
        return ma[s][e][k];
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        unordered_map<int,unordered_map<int,unordered_map<int,int>>> ma;
        int n=cardPoints.size();
        int result=solve(cardPoints,ma,k,0,n-1);
        return result;
    }
};