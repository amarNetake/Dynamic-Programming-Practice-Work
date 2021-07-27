class Solution {
public:
    int kadanes(vector<int>& arr,int n)
    {
        int maxEndingHere=arr[0];
        int maxSoFar=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            maxEndingHere=max(maxEndingHere+arr[i],arr[i]);
            maxSoFar=max(maxSoFar,maxEndingHere);
        }
        maxSoFar=max(maxSoFar,maxEndingHere);
        return maxSoFar;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum=0;
        int n=arr.size();
        int modulo=1e9+7;
        for(auto x: arr)
        {
            sum=sum+x;
        }
        
        vector<int> newArr;
        for(int i=1;i<=2;i++)
        {
            for(int j=0;j<n;j++)
            {
                newArr.push_back(arr[j]);
            }
        }
        int result;
        if(k==1)
        {
            result=kadanes(arr,n)%modulo;
        }
        
        else if(sum<0)
        {
            result=kadanes(newArr,2*n)%modulo;
        }
        else 
        {
            //result=(kadanes(newArr,2*n)+(k-2)*sum)%modulo
            int s=0;
            for(int i=1;i<=k-2;i++)
            {
                s = ( s + sum )%modulo;
            }
            result= (kadanes(newArr,2*n) + s)%modulo;
        }
        return result<0?0:result;
    }
};