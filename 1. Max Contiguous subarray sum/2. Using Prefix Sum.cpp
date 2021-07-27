// Time complexity:- O(n^2)
// Space Complexity:- O(n)

#include <bits/stdc++.h>
using namespace std;

int findMaxSubarraySum(vector<int>& vect,vector<int>& prefixSum,int n)
{
    int maximum=INT_MIN;
    int sum;
    /*
        As we will be dealing with prefixSum array so run the below loops for size
        of prefixSum which will be 1 larger as we inserted extra 0 in the beginning
    */
    for(int i=0;i<prefixSum.size();i++)  
    {
        for(int j=i+1;j<prefixSum.size();j++)
        {
            sum=prefixSum[j]-prefixSum[i];
            maximum=max(maximum,sum);
        }
    }
    return maximum;
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
	    vector<int> prefixSum;
	    int total=0;
	    for(auto x:vect)
	    {
	        total=total + x;
	        prefixSum.push_back(total);
	    }
	    
	    //Do not forget to insert 0 in beginning to consider all the subarray sums that start from index 0
	    prefixSum.insert(prefixSum.begin(),0);  
	    int sum=findMaxSubarraySum(vect,prefixSum,n);
	    cout<<sum<<"\n";
	}
	return 0;
}