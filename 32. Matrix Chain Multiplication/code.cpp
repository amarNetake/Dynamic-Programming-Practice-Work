#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> vect,int n)
{
    vector<vector<int>> dp(n-1,vector<int>(n-1,0)); //Here dp.size()==dp[0].size() so no need to worry about that complexity
    for(int i=0;i<dp.size();i++)
    {
        dp[i][i]=0;
    }
    
    for(int i=0;i+1<dp.size();i++)
    {
        dp[i][i+1]=vect[i]*vect[i+1]*vect[i+2];
    }
    for(int i=2;i<dp.size();i++)
    {
        for(int j=0;j+i<dp.size();j++)
        {
            int k=0;
            int minimum=INT_MAX;
            while(j+k<j+i)
            {
                int left=dp[j][j+k]; // will generate a matrix of order vect[j] x vect[j+k+1]
                int right=dp[j+k+1][j+i]; //will generate a matrix of order vect[j+k+1] x vect[j+i+1]
                int total = left + right + vect[j]*vect[j+k+1]*vect[j+i+1];
                minimum=min(minimum,total);
                k++;
            }
            dp[j][j+i]=minimum;
        }
    }
    return dp[0][dp.size()-1];
}

int main()
{
    int n;
    cin>>n;
    vector<int> vect(n);
    for(auto& it: vect)
    {
        cin>>it;
    }
    int result=matrixMultiplication(vect,n);
    cout<<result;
}