// O(n) time complexity

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
        int nearestTrue=1;     //Nearest true from in the right of current node
        for(int i=n-2;i>=0;i--)  //We will start from second last node towards right
        {
            if(nums[i]>=nearestTrue)
            {
                reachable[i]=true;
                nearestTrue=1;
            }
            else
            {
                reachable[i]=false;
                nearestTrue++;
            }
        }
        return reachable[0];
    }