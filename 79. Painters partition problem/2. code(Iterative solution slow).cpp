#include <bits/stdc++.h>
using namespace std;

int SUM(vector<int>& sum,int s,int n)
{
    return sum[n]-sum[s];
}

int partition(vector<int>& vect,vector<int>& sum,vector<vector<int>>& dp,int n,int k)
{
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=SUM(sum,0,i);
    }
    
    for(int i=1;i<=k;i++)
    {
        dp[i][1]=vect[1];
    }
    
    for(int i=2;i<=k;i++)
    {
        for(int j=2;j<=n;j++)
        {
            int best=INT_MAX;
            for(int p=1;p<=j;p++)
            {
                best=min(best,max(dp[i-1][p],SUM(sum,p,j)));
            }
            dp[i][j]=best;
        }
    }
    return dp[k][n];
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
	    
	    int k;
	    cin>>k;
	    if(k>n)
	    {
	        cout<<-1<<"\n";
	        continue;
	    }
	    vector<int> sum;
	    int total=0;
	    for(int x: vect)
	    {
	        total+=x;
	        sum.push_back(total);
	    }
	    
	    vect.insert(vect.begin(),0);
	    sum.insert(sum.begin(),0);
	    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
	    int result=partition(vect,sum,dp,n,k);
	    cout<<result<<"\n";
	}
	return 0;
}