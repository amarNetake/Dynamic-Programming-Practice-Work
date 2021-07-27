#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& values,vector<int>& weights,int n,int maxW)
{
    if(maxW==0)
    {
        return 0;
    }
    values.insert(values.begin(),0);
    weights.insert(weights.begin(),0);
    vector<vector<int>> dp(n+1,vector<int>(maxW+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxW;j++)
        {
            if(weights[i]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(weights[i]==j)  
            {
                //Maxprofit by either just take this one item as its weight will consume entire knapsack or exclude by taking dp[i-1][j]
                dp[i][j]=max(values[i],dp[i-1][j]);
            }
            else if(weights[i]<j)
            {
                dp[i][j]=max(values[i]+dp[i-1][j-weights[i]],dp[i-1][j]);  //maxprofit by either -> include or exclude
            }
        }
    }
    return dp[n][maxW];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int maxW;
	    cin>>maxW;
	    vector<int> values(n);
	    for(auto& it: values)
	    {
	        cin>>it;
	    }
	    vector<int> weights(n);
	    for(auto& it:weights)
	    {
	        cin>>it;
	    }
	    int maxProfit=knapsack(values,weights,n,maxW);
	    cout<<maxProfit<<"\n";
	}
	return 0;
}