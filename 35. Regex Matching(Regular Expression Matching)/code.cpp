/*
  Pattern will be along x axis and string given will be along y axis. Now we will append a " " in front to denote the empty
  part.
  If ( ptrn[i]==str[j] ) both are characters and matched then dp[i][j]= dp[i-1][j-1]
  
  Else If ( ptrn[i]== '.' ) then dp[i][j]=dp[i-1][j-1] as '.' can take care of jth character of string whatever it is
  
  Else if ( ptrn[i]=='*' )  then we can either totally exclude (i-1)th character or take 0 occurrences of it. So to check if that 
  is possibly resulting in string matching with pattern check if dp[i-2][j]==true if it is then dp[i][j]=dp[i-2][j].
  Otherwise we need to take 1 or more occurrences of character ptrn[i-1]. So now check if
  (ptrn[i-1]=='.' OR ptrn[i-1]==str[j]) then dp[i][j]=dp[i][j-1] otherwise dp[i][j]=false;

*/
bool isMatch(string str, string ptrn) {
        
        int n=ptrn.size();
        int m=str.size();
        ptrn=" "+ptrn;
        str=" "+str;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        for(int i=0;i<=n;i++)
        {
            if(ptrn[i]==str[0])
            {
                dp[i][0]=true;
            }
            else if(ptrn[i]=='*')
            {
                dp[i][0]=dp[i-2][0];
            }
            else
            {
                dp[i][0]=false;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(ptrn[i]==str[j])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(ptrn[i]=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(ptrn[i]=='*')
                {
                    if(dp[i-2][j]==true)
                    {
                        dp[i][j]=true;
                    }
                    else if(ptrn[i-1]!=str[j] && ptrn[i-1]!='.')
                    {
                        dp[i][j]=false;
                    }
                    else if(ptrn[i-1]!=str[j] && ptrn[i-1]=='.')
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                    else if(ptrn[i-1]==str[j])
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
        return dp[n][m];
    }