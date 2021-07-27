// Using Kadane's algorithm to find maximum sum continuous subarray
// Time complexity: - O(n)
// Space Complexity:- O(1)

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> vect,int n)
{
    int MaxSumSoFar=vect[0];  //This will hold the overall largest subarray sum
    int MaxSumEndingHere=vect[0]; //This will hold the largest continuous subarray sum that ends at index i
    for(int i=1;i<n;i++)
    {
        MaxSumEndingHere=max(MaxSumEndingHere + vect[i], vect[i]); //subarray with largest sum that ends at index i
        MaxSumSoFar=max(MaxSumSoFar,MaxSumEndingHere);
    }
    return MaxSumSoFar;  
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
	    int maxSum=subarraySum(vect,n);
	    cout<<maxSum<<"\n";
	}
	return 0;
}