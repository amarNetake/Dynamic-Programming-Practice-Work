#include<bits/stdc++.h>
using namespace std;

int subsetSum(vector<int>& vect,int n,int sum)
{
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<dp.size();i++)  //If we want to find sum 0 it is always possible so fill 0th column with true
    {
        dp[i][0]=true;
    }
    for(int i=1;i<dp[0].size();i++)//If we want to find any sum and if we have no element or single element '0' then we can never generate sum
    {
        dp[0][i]=false;
    }
    //i or row labels will specify the number of items from array
    for(int i=1;i<dp.size();i++)
    {
        //j or column labels specify the sum j
        for(int j=1;j<dp[i].size();j++)
        {
            if(dp[i-1][j]==true||(j-vect[i]>=0&&dp[i-1][j-vect[i]]==true))
            {
                dp[i][j]=true;
            }
            else
            {
                dp[i][j]=false;
            }
        }
    }
    return dp[n][sum];
}

int main()
{
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
        int sum;
        cin>>sum;
        vect.insert(vect.begin(),0);
        bool result=subsetSum(vect,n,sum);
        result==true? cout<<"True\n": cout<<"False\n";
    }
}