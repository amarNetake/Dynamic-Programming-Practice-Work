int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        
        //Let us create a vector 'lis' to keep track of the length of longest increasing subsequence ending at index i for all i from 0 to n-1
        vector<int> lis(n,1);
        
        //Let us create a vector that will keep track of number of longest increasing subsequences ending at index i for all i from 0 to n-1
        vector<int> counter(n,1); //Initialized with counter=1 as initially total longest increasing subsequences ending at index i will be 1
        int maxLength;
        bool flag;
        for(int i=1;i<n;i++)
        {
            maxLength=1;  //Here 'maxLength' inside this loop will keep track of LIS till index i. As initially Length of LIS till i is 1 
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && lis[i]<=lis[j]+1) //As there could be multiple LIS ending at i. So take '<=' instead of just '<'
                {
                    lis[i]=lis[j]+1;
                    if(lis[i]>maxLength)
                    {
                        maxLength=lis[i];
                        counter[i]=counter[j];
                        
                    }
                    else if(lis[i]==maxLength)
                    {
                        counter[i]=counter[i]+counter[j]; 
                    }
                }
            }
        }
        
        maxLength=*max_element(lis.begin(),lis.end());  //Now here 'maxLength' to find out overall maximum length
        
        int overallCount=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]==maxLength)  //If lis[i] is having overall maxLength then add total LISs till i to overall count
            {
                overallCount=overallCount + counter[i];
            }
        }
        return overallCount;
    }