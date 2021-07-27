 int longestPalindromeSubseq(string str) {
        
        int n=str.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        int maxLen=0;
        
        for(int w=1;w<=n;w++)   // w stands for window size
        {
            for(int i=0;i+w-1<n;i++)  // starting index of window is i and ending index is i+w-1 thus making size of window being w
            {
                if(w==1) //If size of window is 1 then it is definately a palindrome  (Base case)
                {
                    dp[i][i+w-1]=1;
                    maxLen=1;
                }
                else if(w==2)   //  (Base case 2)
                {
                    if(str[i]==str[i+w-1])
                    {
                        dp[i][i+w-1]=2;
                        maxLen=2;
                    }
                    else
                    {
                        dp[i][i+w-1]=1;
                    }
                }
                else
                {
                    if(str[i]==str[i+w-1])
                    {
                        dp[i][i+w-1]= 2 + dp[i+1][(i+w-1)-1];
                        maxLen=max(maxLen,dp[i][i+w-1]);
                    }
                    else
                    {
                        dp[i][i+w-1]= max({dp[i+1][(i+w-1)-1] , dp[i+1][i+w-1] , dp[i][(i+w-1)-1]});
                    }
                }
            }
        }
        return maxLen;     
    }