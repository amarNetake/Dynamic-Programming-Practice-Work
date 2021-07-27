#include <bits/stdc++.h>
using namespace std;

int LCS(string str1,string str2,int n1,int n2)
{
	/*
        dp[i][j] where i and j are length of str1 and str2 under consideration and dp[i][j]=LCS for string str1 of length i and str2 of length j
    */
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    
    for(int i=1;i<=n1;i++)  //Iterating over str1 from string length 1 to n1
    {
        for(int j=1;j<=n2;j++)  //Iterating over str2 from string length 1 to n2
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]= 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j]= max( dp[i-1][j] , dp[i][j-1] );
            }
        }
    }
    return dp[n1][n2];
}

