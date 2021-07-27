class Solution {
public:
    void  robUtil(vector<int>& nums,int i,int total,int& maximum,int flag)
    {
        if(i==nums.size())
        {
            if(maximum<total)
            {
                maximum=total;
            }
            return;
        }
        if(flag==0)  //flag=0 implies we did not included previous house wealth so in current house we have 2 options
        {
            robUtil(nums,i+1,total+nums[i],maximum,1);
            robUtil(nums,i+1,total,maximum,0);
        }
        else if(flag==1)  //flag=1 implies we included previous house's wealth so we cannot include current house wealth 
        {
            robUtil(nums,i+1,total,maximum,0);  //We need to pass flag as 0 as we are not including current house's wealth
        }
    }
    
    int rob(vector<int>& nums) {
        int flag=0;
        int maximum=0;
        int total=0;
        robUtil(nums,0,total,maximum,flag);
        return maximum;
    }
};