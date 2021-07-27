int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
        {
            return n;
        }
        vector<int> up(n,0);
        vector<int> down(n,0);
        int maxLen=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]&& up[i]<down[j]+1)
                {
                    up[i]=down[j]+1;
                }
                else if(nums[j]>nums[i] && down[i]<up[j]+1)
                {
                    down[i]=up[j]+1;
                }
                
                maxLen=max({maxLen,up[i],down[i]});
            }
        }
        return maxLen+1;
    }