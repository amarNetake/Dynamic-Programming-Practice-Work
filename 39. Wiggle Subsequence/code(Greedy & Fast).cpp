int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        if(n<2)
        {
            return n;
        }
        int i=1;
        while(i<n && nums[i]==nums[i-1]) //Get rid of all the duplicates initially occurring in the array
        {
            i++;
        }
        if(i==n)  //If we reached to end of array implies entire array has same elements
        {
            return 1;
        }
        int c=2;
        bool inc=nums[i]>nums[i-1]; //Note the initial behaviour of the array
        while(i<nums.size())
        {
            if(inc==true)
            {
                while(i<n && nums[i]>=nums[i-1])
                {
                    i++;
                }
                if(i<nums.size()) //The condition failed before the end of array so implies currently nums[i]>=nums[i-1]
                {
                    c++;
                }
                inc=false;
            }
            if(inc==false)
            {
                while(i<n && nums[i]<=nums[i-1])
                {
                    i++;
                }
                if(i<nums.size()) //The condition failed before the end of array so implies currently nums[i]<=nums[i-1]
                {
                    c++;
                }
                inc=true;
            }
        }
        return c;
    }