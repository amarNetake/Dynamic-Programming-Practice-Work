class Solution{
public:
    int offerings(int n, int arr[]){
        // code here
        vector<int> ltr(n);
        
        ltr[0]=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1]) ltr[i]=ltr[i-1]+1;
            
            if(arr[i]<=arr[i-1]) ltr[i]=1;
        }
        
        vector<int> rtl(n);
        
        rtl[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1]) rtl[i]=rtl[i+1]+1;
            
            if(arr[i]<=arr[i+1]) rtl[i]=1;
        }
        
        int minOfferings=0;
        
        for(int i=0;i<n;i++)
        {
            minOfferings= minOfferings + max(ltr[i],rtl[i]);
        }
        return minOfferings;
    }
};