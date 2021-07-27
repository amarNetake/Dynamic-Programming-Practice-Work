#include <bits/stdc++.h>
using namespace std;

int maxSumIS(vector<int> vect,int n)
{
    vector<int> msis(n);
    for(int i=0;i<n;i++)
    {
        msis[i]=vect[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(vect[j]<vect[i]&&msis[i]<msis[j]+vect[i])
            {
                msis[i]=msis[j]+vect[i];
            }
        }
    }
    int max=msis[0];
    for(int i=1;i<n;i++)
    {
        if(max<msis[i])
        {
            max=msis[i];
        }
    }
    return max;
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
	    for(int i=0;i<n;i++)
	    {
	        cin>>vect[i];
	    }
	    int max=maxSumIS(vect,n);
	    cout<<max<<"\n";
	}
	return 0;
}