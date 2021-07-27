#include <bits/stdc++.h>
using namespace std;

int decodeWays(string str,int n)
{
    if(n==0||(n==1&&str[0]!='0'))
    {
        return 1;
    }
    if(str[0]=='0'||str[n-1]=='0' && (str[n-2]=='0'||str[n-2]-'0'>=3))
    {
        return 0;
    }
    vector<int> dp(n+1,0);
    dp[0]=1; 
    dp[1]=1;
    
    str="0"+str;
    
    for(int i=2;i<=n;i++)
    {
        int twoDig=(str[i-1]-'0')*10 + (str[i]-'0');
        if(twoDig==0)  //If we have two consecutive zeros 
        {
            return 0;
        }
        else if(twoDig>=10 && twoDig<=26 && str[i]!='0') //We can consider current digit individually as well as in combination with its previous digit as two digit
        {
            dp[i]=dp[i-1] + dp[i-2];
        }
        else if(twoDig>=10 && twoDig<=26 && str[i]=='0') // 0 can only be taken as combination with its previous digit as two digit
        {
            dp[i]=dp[i-2];
        }
        else if(twoDig>26 && str[i]=='0') //Neither 0 can be taken individually nor as combination with its previous digit as two digit
        {
            return 0;
        }
        else if(twoDig>26 && str[i]!='0') //We can only consider current digit individually and not with the combination with its previous digit
        {
            dp[i]=dp[i-1];
        }
        else if(twoDig<10)  //We have already handled the 00 case so if control reaches here => twoDig>=1 and twoDig<10
        {
            dp[i]=dp[i-1];
        }
    }
    return dp[n];
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
	    int count=decodeWays(str,n);
	    cout<<count<<"\n";
	}
	return 0;
}