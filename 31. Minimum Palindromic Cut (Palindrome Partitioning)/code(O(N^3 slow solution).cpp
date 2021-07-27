// Palindrome Partition OR Minimum Palindromic Cut
/*
    Minimum cuts required to make all the partitions a palindrome
*/

// THIS IS A O(n^3) SOLUTION
int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
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
        
        vector<vector<int>> result(n,vector<int>(n,0));
        for(int i=0;i+1<n;i++)
        {
            if(str[i]!=str[i+1])
            {
                result[i][i+1]=1;
            }
        }
        
        for(int i=2;i<n;i++)
        {
            for(int j=0;j+i<n;j++)
            {
                /*
                	If string under consideration is already palindrome so minimum partition 
                	cut will be 0 with which 'result' already assigned
                */
                if(dp[j][j+i]==true)
                {
                    continue;
                }

                // else if the entire string is not palindrome there will be atleast one cut
                int k=0;
                int minimum=INT_MAX;
                while(j+k<j+i)
                {
                    int left=result[j][j+k];  //Minimum partitions in left partition of current string
                    int right=result[j+k+1][j+i]; //Minimum partitions in right partition of current string
                    int total=left+right+1; //1 extra cut will be the cut that seperates left and right
                    minimum=min(minimum,total);
                    k++;
                }
                result[j][j+i]=minimum;
            }
        }
        return result[0][n-1];
    }