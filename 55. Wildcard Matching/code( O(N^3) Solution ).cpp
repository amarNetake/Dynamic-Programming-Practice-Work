bool isMatch(string s, string p) {
        s=" "+s;
        p=" "+p;
        vector<vector<bool>> dp(p.length(),vector<bool>(s.length(),false));
        dp[0][0]=true;
        
        for(int i=1;i<p.length();i++)
        {
            if((p[i]>='a' && p[i]<='z')|| p[i]=='?')
            {
                dp[i][0]=false;
            }
            if(p[i]=='*')
            {
                dp[i][0]=dp[i-1][0];
            }
        }
        
        for(int i=1;i<s.length();i++)
        {
            dp[0][i]=false;
        }
        
        for(int i=1;i<p.length();i++)
        {
            for(int j=1;j<s.length();j++)
            {
                if(p[i]>='a'&&p[i]<='z')
                {
                    if(p[i]==s[j])
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                else if(p[i]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i]=='*')
                {
                    auto result= [&](int i,int j){
                        
                        bool result=false;
                        for(int k=0;k<=j;k++)
                        {
                            result=dp[i-1][k];
                            if(result==true)
                            {
                                break;
                            }
                        }
                        return result;
                    };
                    dp[i][j]=result(i,j);
                }
            }
        }
        return dp[p.length()-1][s.length()-1];
    }