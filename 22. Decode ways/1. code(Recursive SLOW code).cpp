#include <bits/stdc++.h>
using namespace std;

int decodeways(string str,vector<int>& dp,int curr,int n)
{
    if(curr==n)
    {
        return 1;
    }
    if(str[curr]=='0')
    {
        dp[curr]=0;
        return 0;
    }
    int totalways;
    if(curr<n-1)
    {
        int num=(str[curr] - '0')*10 + (str[curr+1] - '0');
        if(num<=26)
        {
            totalways=decodeways(str,dp,curr+1,n) + decodeways(str,dp,curr+2,n);
            dp[curr]=totalways;
        }
        else
        {
            totalways=decodeways(str,dp,curr+1,n);
            dp[curr]=totalways;
        }
    }
    else if(curr==n-1)
    {
        totalways=decodeways(str,dp,curr+1,n);
        dp[curr]=totalways;
    }
    return totalways;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string str;
	    cin>>str;
	    vector<int> dp(n,-10);
	    int ways=decodeways(str,dp,0,n);
	    if(dp[0]==0)
	    {
	        cout<<0<<"\n";
	    }
	    else
	    {
	        cout<<ways<<"\n";
	    }
	}
	return 0;
}