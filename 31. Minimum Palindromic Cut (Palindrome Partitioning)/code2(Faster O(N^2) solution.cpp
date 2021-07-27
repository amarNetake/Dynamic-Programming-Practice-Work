int palindromicPartition(string str)
    {
        int n=str.length();
        if(n<2)
        {
            return 0;
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        for(int i=0;i+1<n;i++)
        {
            if(str[i]==str[i+1])
            {
                dp[i][i+1]=true;
            }
        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j+i<n;j++)
            {
                if(str[j]==str[j+i] && dp[j+1][j+i-1]==true)
                {
                    dp[j][j+i]=true;
                }
            }
        }
        
        vector<int> result(n,0);  //  Analyze suffix if suffix is palindrome then total cuts= 1 + minimum cuts of its prefix
        result[0]=0;  //As length of suffix till first character is 1 as is a palindrome and its prefix is of 0 length hence no cuts
        
        if(str[0]==str[1]) //We do not have to put any cut if str[0]==str[1]
        {
            result[1]=0;  //No cuts required
        }
        else
        {
            result[1]=1;  
        }
        for(int i=2;i<n;i++)
        {
            if(dp[0][i]==true)
            {
                result[i]=0;
                continue;
            }
            int minimum=INT_MAX;
            for(int j=i;j>=1;j--)
            {
                if(dp[j][i]==true)
                {
                    int cuts= 1 + result[j-1];
                    minimum=min(minimum,cuts);
                }
            }
            result[i]=minimum;
        }
        return result[n-1];
    }