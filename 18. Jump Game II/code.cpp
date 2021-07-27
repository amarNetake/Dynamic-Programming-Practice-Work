// O(n^2) time complexity

// This problem is an equivalent to minimum jumps to reach to the end
int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
        {
            return 0;
        }
        //NOTE:- It is given that you can always reach at the last index so first will always be true and count will be finite
        vector<bool> reachable(n);
        reachable[n-1]=true;
        for(int i=n-2;i>=0;i--)
        {
            int count=1;
            if(nums[i]>=count)
            {
                reachable[i]=true;
                count=1;
            }
            else
            {
                reachable[i]=false;
                count++;
            }
        }
        int nextMaxReachable=INT_MIN;
        int nextJump=0;
        int count=0;
     
        for(int i=0;i<n;i=nextJump)
        {
            nextJump=i+1;   //In general if i+nums[i] turns out to be i itself OR if nums[i] is 0. 
            for(int j=i+nums[i];j>i;j--)
            {
                if(j>=n-1)
                {
                    count++;
                    return count;
                }
                if(reachable[j]==false)
                {
                    continue;
                }
                if(nums[j] + j > nextMaxReachable)
                {
                    nextJump=j;
                    nextMaxReachable=nums[j]+j;
                    if(nextMaxReachable>=n-1)
                    {
                        count=count+2; //Jump from index i to j and j to n-1
                        return count;
                    }
                }
            }
            count++;
            i=nextJump;
            nextMaxReachable=0;
        }
        return count;
    }