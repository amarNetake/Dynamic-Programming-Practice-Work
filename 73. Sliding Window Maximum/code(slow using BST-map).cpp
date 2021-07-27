class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int,greater<int>> ma;
        int j=0;
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            if(i>=k)
            {
                ma[nums[j]]--;
                if(ma[nums[j]]==0)  ma.erase(nums[j]);
                j++;
            }
            ma[nums[i]]++;
            if(i>=k-1)
            {
                result.push_back(ma.begin()->first);
            }
        }
        return result;
    }
};