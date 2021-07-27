// Time complexity:- O(n^3)
// Space complexity:- O(1)

#include <bits/stdc++.h>
using namespace std;

int findMaxSubarraySum(vector<int>& vect,int n)
{
    int maximum=INT_MIN;
    int sum;
    //Iterating through all the possible subarrays and finding the sum of each subarray individually and keeping track of maximum sum
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum=0;
            for(int k=i;k<=j;k++)
            {
                sum=sum+vect[k];
            }
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
	    int sum=findMaxSubarraySum(vect,n);
	    cout<<sum<<"\n";
	}
	return 0;
}