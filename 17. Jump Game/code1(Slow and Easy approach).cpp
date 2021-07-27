// O(n^2) time complexity

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
        vector<bool> reachable(n);
        reachable[n-1]=true;
        for(int i=n-2;i>=0;i--)
        {
            int count=1;
            for(int j=i+1;j<n;j++)
            {
                if(reachable[j]==true)
                {
                    break;
                }
                count++;
                if(count>nums[i])
                {
                    break;
                }
            }
            if(nums[i]>=count)
            {
                reachable[i]=true;
            }
            else
            {
                reachable[i]=false;
            }
        }
        return reachable[0];
    }