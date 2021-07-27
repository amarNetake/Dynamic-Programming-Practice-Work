class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<int> dp(n,INT_MIN);
        dp[n-1]=nums[n-1];
        map<int,int,greater<int>> ma;
        ma[dp[n-1]]++;
        int j=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(i<n-1-k) //We need the maximum among the next k entries in dp so we will enter this for all indexes<last index-k or i<(n-1)-k
            {
                ma[dp[j]]--;
                if(ma[dp[j]]==0) ma.erase(dp[j]);
                j--;
            }
            dp[i]=nums[i]+ ma.begin()->first;
            ma[dp[i]]++;
            
        }
        for(auto x: dp)  cout<<x<<"  ";
        return dp[0];
    }
};