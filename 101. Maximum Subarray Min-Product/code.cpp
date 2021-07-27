class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        int modulo=1e9+7;
        
        vector<int> left_bound(n);
        vector<int> right_bound(n);
        
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(s.empty()==false && nums[s.top()]>=nums[i]) s.pop();
            if(s.empty()==true) left_bound[i]=0;
            else left_bound[i]=s.top()+1;
            s.push(i);
        }
        while(s.empty()==false)  s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==false && nums[s.top()]>=nums[i]) s.pop();
            if(s.empty()==true) right_bound[i]=n-1;
            else right_bound[i]=s.top()-1;
            s.push(i);
        }
        
        vector<long int> sums;
        sums.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            long int sum=(sums[i]+nums[i]);
            sums.push_back(sum);
        }
    
        
        long int maxResult=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int left=left_bound[i];
            int right=right_bound[i]+1;
            long int sum= (sums[right]-sums[left]);
            maxResult=max(maxResult,(sum*nums[i]));
        }
        return maxResult%modulo;
    }
};