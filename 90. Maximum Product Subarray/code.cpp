class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxTillHere=nums[0];
        int maxSoFar=nums[0];
        vector<int> negSuffix(n,0);
        vector<int> negPrefix(n,0);
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            negSuffix[i]=count;
            if(nums[i]<0) count++;
            else if(nums[i]==0) count=0;
        }
        
        count=0;
        
        for(int i=0;i<n;i++)
        {
            negPrefix[i]=count;
            if(nums[i]<0) count++;
            else if(nums[i]==0) count=0;
        }
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>0)  
            {
                if(maxTillHere>=0) maxTillHere= maxTillHere==0?nums[i]:maxTillHere*nums[i];
                else if(maxTillHere < 0) maxTillHere= negSuffix[i]>0?maxTillHere*nums[i]:nums[i];
            }
            else if(nums[i]<0)
            {
                if(negSuffix[i]>0)
                {
                    maxTillHere= maxTillHere==0?nums[i]:maxTillHere*nums[i];
                }
                else
                {
                    maxTillHere=max(maxTillHere*nums[i],nums[i]);
                }
            }
            else if(nums[i]==0)  maxTillHere=nums[i];
            
            maxSoFar=max(maxSoFar,maxTillHere);
        }
        
        //Doing the same process in reverse direction for cases like [-2,-3,-5]
        // If we only do one way then we end up getting 6. Hence we need to do from both the sides
        maxTillHere=nums[n-1]; 
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>0)  
            {
                if(maxTillHere>=0) maxTillHere= maxTillHere==0?nums[i]:maxTillHere*nums[i];
                else if(maxTillHere < 0) maxTillHere= negPrefix[i]>0?maxTillHere*nums[i]:nums[i];
            }
            else if(nums[i]<0)
            {
                if(negPrefix[i]>0)
                {
                    maxTillHere= maxTillHere==0?nums[i]:maxTillHere*nums[i];
                }
                else
                {
                    maxTillHere=max(maxTillHere*nums[i],nums[i]);
                }
            }
            else if(nums[i]==0)  maxTillHere=nums[i];
            
            maxSoFar=max(maxSoFar,maxTillHere);
        }
        return maxSoFar;
    }
};