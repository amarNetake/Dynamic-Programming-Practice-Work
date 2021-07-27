class Solution {
public:
    int LIS(vector<int>& nums)
    {
        vector<int> dp;
        for(int i=0;i<nums.size();i++)
        {
            int left=0,right=dp.size();
            while(left<right)
            {
                int mid= left + (right-left)/2;
                if(dp[mid]>=nums[i])   right=mid;
                else  left=mid+1;
            }
            if(right==dp.size()) dp.push_back(nums[i]);
            else  dp[right]=nums[i];
        }
        return dp.size();
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        // Since it is given that target has all distinct element this method will work
        unordered_map<int,int> ma;   // target[i] -> i mapping
        for(int i=0;i<target.size();i++)
        {
            ma[target[i]]=i;
        }
        vector<int> nums;  // This will store the index of arr[i] in target vector if arr[i] is present in target.
        for(int i=0;i<arr.size();i++)
        {
            if(ma.find(arr[i])!=ma.end())
            {
                nums.push_back(ma[arr[i]]);
            }
        }
        int len=LIS(nums);
        
        return target.size()>=len?target.size()-len:0;
        
    }
};