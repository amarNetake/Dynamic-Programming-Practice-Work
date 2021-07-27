// Variation of Longest Increasing subsequence
#include<bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>& rod,int n)
{
    rod.insert(rod.begin(),0);
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=rod[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int result=rod[j] + dp[i-j];
            dp[i]=max(dp[i],result);
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    vector<int> rod(n);
    for(auto& it: rod)
    {
        cin>>it;
    }
    int maxProfit=rodCutting(rod,n);
    cout<<maxProfit;
}