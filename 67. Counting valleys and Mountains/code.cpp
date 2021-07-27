/*
    This question is just an application of catalan Numbers.
    Catalan Numbers: 1, 1, 2, 5, 14, 42, ...
     C0= 1,  C1=1

     C2= C0*C1 + C1*C0
     C3= C0*C2 + C1*C1 + C2*C0
     C4= C0*C3 + C1*C2 + C2*C1 + C3*C0
     .
     .
     .
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int x=2;x<=n;x++)
    {
        for(int i=0,j=x-1;i<x;i++,j--)
        {
            dp[x]=dp[x]+ dp[i]*dp[j];
        }
    }
    cout<<dp[n];
    return 0;
}