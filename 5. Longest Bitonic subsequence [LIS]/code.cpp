int LongestBitonicSequence(vector<int>nums)
{
    // code here
    int n=nums.size();
    vector<int> lis(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j] < nums[i] && lis[i] < lis[j] + 1)
            {
                lis[i]=lis[j] + 1;
            }
        }
    }
    
    vector<int> lds(n,1);
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(nums[j] < nums[i] && lds[i] < lds[j] + 1)
            {
                lds[i]=lds[j] + 1;
            }
        }
    }
    int maxlength=0;
    for(int i=0;i<n;i++)
    {
        maxlength=max(maxlength,lis[i]+lds[i]-1);
    }
    return maxlength;
}