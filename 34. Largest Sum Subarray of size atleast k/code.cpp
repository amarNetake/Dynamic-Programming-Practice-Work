#include <bits/stdc++.h>
using namespace std;

int largestSumSubarray(vector<int>& vect,vector<int>& prefixSum,vector<int>& kadaneSum,int k,int n)
{
    /*
        dp[i] will store the largest subarray sum that ends at i of size atleast k and is 
        computed as:-
        dp[i]= sum of k-1 elements ending at ith index + kadaneSum till kth item 
        Let us say k is 4
        then 
        dp[8]= (sum of items at index 6, 7 and 8 ) + kadaneSum[5]
        
        NOTE 2: prefixSum[i] - prefixSum[j] gives sum from index j+1 till index i
         
        hence
         dp[8]= prefixSum[8] - prefixSum[5] + kadanes[5]
                    \               /             |
                     \             /              |
                      \           /               |
                       -----  ----                |
                            \/                    |
                (Sum from index 6 to 8)     (maxSum till index 5)
    */
    vector<int> dp(n,INT_MIN);
    dp[k-1]=prefixSum[k-1];
    for(int i=k;i<n;i++)
    {
        dp[i]=prefixSum[i]-prefixSum[i-k+1]+ kadaneSum[i-k+1]; 
    }
    
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxSum=max(maxSum,dp[i]);
    }
    return maxSum;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> vect(n);
	    for(auto& it: vect)
	    {
	        cin>>it;
	    }
	    int k;
	    cin>>k;
	    
	    vector<int> prefixSum(n);
        vector<int> kadaneSum(n);
        
        int total=0;
        for(int i=0;i<n;i++)
        {
            total=total + vect[i];
            prefixSum[i]=total;
        }
        
        int maxEndingHere=vect[0];
        kadaneSum[0]=vect[0];
        for(int i=1;i<n;i++)
        {
            maxEndingHere=max(maxEndingHere + vect[i], vect[i]);
            kadaneSum[i]=maxEndingHere;
        }
        
	    int maxSum=largestSumSubarray(vect,prefixSum,kadaneSum,k,n);
	    cout<<maxSum<<"\n";
	}
	return 0;
}