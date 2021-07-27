bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
        {
            return true;
        }
        if(nums[0]==0)
        {
            return false;
        }
        int reachable=0;
        for(int i=0;i<n-1&&i<=reachable;i++)
        {
            reachable=max(reachable, i+nums[i]);
            
        }
        if(reachable>=n-1)
        {
            return true;
        }
        return false;
    }