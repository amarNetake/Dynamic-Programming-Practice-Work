// Using longest increasing subsequence method
// Time complexity:-O(n^2) in worst case

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=2)
        {
            return false;
        }
        vector<int> lis(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i]  && lis[i] < lis[j] + 1)
                {
                    lis[i]=lis[j] + 1;
                    if(lis[i]>=3)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};