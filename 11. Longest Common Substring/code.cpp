//Find the longest common suffix by comparing every prefix of the given two strings

#include<bits/stdc++.h>
using namespace std;

int LCSubstr(string str1,string str2,int n1,int n2)
{
    if(n1==0||n2==0)
    {
        return 0;
    }
    
    //Let us create a 2-D array 'dp' of dimensions (n1+1)x(n2+1) initialized with all zeros.
    //dp[i][j] will hold the length of longest common substring that end at str1[i] and str2[j]

    // We first need to ensure that ith character must be at ith position as we are dealing with the lengths
    str1.insert(str1.begin(),'0');
    str2.insert(str2.begin(),'0');
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0)); 

    int maxLength=0;
    for(int i=1;i<=n1;i++)  //Here i will denote the length of string str1 that is under consideration
    {
        for(int j=1;j<=n2;j++)   //Here j will denote the length of string str2 that is under consideration
        {
            if(str1[i]==str2[j]) 
            {
                dp[i][j]=1+dp[i-1][j-1];
                maxLength=max(maxLength,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    
    return maxLength;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2;
        cin>>n1>>n2;
        string str1,str2;
        cin>>str1>>str2;
        
        int maxLength=LCSubstr(str1,str2,n1,n2);
        cout<<maxLength<<"\n";
    }
}