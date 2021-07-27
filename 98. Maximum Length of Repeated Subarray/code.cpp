class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        nums1.insert(nums1.begin(),-10); //Inserted -10 randomly
        nums2.insert(nums2.begin(),-20); //Inserted -20 randomly however we could have inserted anything here
        int maxScore=0;
        for(int i=1;i<nums1.size();i++)
        {
            for(int j=1;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    maxScore=max(maxScore,dp[i][j]);
                }
            }
        }
        return maxScore;
    }
};