#include <bits/stdc++.h>
using namespace std;

int SUM(vector<int>& sum,int i,int n)
{
    
    return sum[n]-sum[i];
}

int partition(vector<int>& vect,vector<int>& sum,vector<vector<int>>& dp,int n,int k)
{
    if(k==1||k==0)
    {
        return SUM(sum,0,n);
    }
    if(dp[n][k]!=-10)
    {
        return dp[n][k];
    }
	int best=INT_MAX;
	for(int i=n-1;i>=1;i--)
	{
	    best=min(best,max(partition(vect,sum,dp,i,k-1),SUM(sum,i,n)));
	}
	dp[n][k]=best;
	return best;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n==0)
	    {
	        cout<<-1<<"\n";
	        continue;
	    }
	    
	    vector<int> vect(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>vect[i];
	    }
	    int k;
	    cin>>k;
	    if(k>n)
	    {
	        cout<<-1<<"\n";
	        continue;
	    }
	    int total=0;
	    vector<int> sum;
	    for(int x: vect)
	    {
	        total=total + x;
	        sum.push_back(total);
	    }
	    vect.insert(vect.begin(),0);
	    sum.insert(sum.begin(),0);
	    vector<vector<int>> dp(n+1,vector<int>(k+1,-10));
	    int best=partition(vect,sum,dp,n,k);
	    cout<<best<<"\n";
	}
	return 0;
}