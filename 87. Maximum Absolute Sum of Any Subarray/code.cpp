class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSoFar=0;
        int n=nums.size();
        if(n==0) return 0;
        int minTillHere=nums[0];
        int maxEndingHere=nums[0];
        maxSoFar=max(maxSoFar,abs(minTillHere));
        for(int i=1;i<n;i++)
        {
            if(minTillHere+nums[i]<nums[i]) minTillHere=minTillHere+nums[i];
            else minTillHere=nums[i];
            if(maxEndingHere+nums[i]>nums[i]) maxEndingHere=maxEndingHere+nums[i];
            else maxEndingHere=nums[i];
            maxSoFar=max({maxSoFar,abs(minTillHere),abs(maxEndingHere)});
        }
        return maxSoFar;
    }
};