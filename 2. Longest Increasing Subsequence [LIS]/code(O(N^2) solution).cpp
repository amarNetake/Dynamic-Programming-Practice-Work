#include <bits/stdc++.h>
using namespace std;

int LgstIncSubseq(vector<int> vect,int n)
{
    /*
        Let us create an array 'lis' where lis[i] will hold the length of longest increasing subsequence 
        that ends at index i
    */
    vector<int> lis(n,1);  //Initially the largest subsequence of every element ending with itself is on length 1.

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(vect[j] < vect[i] && lis[i] < lis[j] + 1)
            {
                lis[i]= lis[j] + 1;
            }
        }
    }
    
    int maxLength=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxLength=max(maxLength,lis[i]);
    }
    return maxLength;
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
	    int maxLength=LgstIncSubseq(vect,n);
	    cout<<maxLength<<"\n";
	}
	return 0;
}