// O(N^3) time complexity

bool isValid(string str,int s,int e)
{
    int count=0;
    for(int i=s;i<=e;i++)
    {
        if(str[i]=='(')
        {
            count--;
        }
        else if(str[i]==')')
        {
            count++;
            if(count>0)
            {
                return false;
            }
        }
    }
    if(count==0)
    {
        return true;
    }
    return false;
}

int longestValidParentheses(string str) 
{
    int n=str.length();
    if(n==0)
    {
        return 0;
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    int maxLength=0;
    for(int i=0;i+1<n;i++)
    {
        if(str[i]=='('&&str[i+1]==')')
        {
            dp[i][i+1]=1;
            maxLength=2;
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int j=0;j+i<n;j++)
        {
            if(((j+i)-j+1)%2==1)  //if length of substring from starting index=j and ending index=j+i is odd
            {
                dp[j][j+i]=0;
            }
            else if(str[j]=='('&& str[j+i]==')')
            {
                if(dp[j+1][j+i-1]==1 || isValid(str,j,j+i)==true)
                {
                    dp[j][j+i]=1;
                    maxLength=max(maxLength,(j+i)-j+1);
                }
            }
        }
    }
     
    return maxLength;
}