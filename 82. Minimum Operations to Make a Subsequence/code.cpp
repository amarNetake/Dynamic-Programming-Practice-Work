class Solution {
public:
    int LCS(vector<int>& vect1,vector<int>& vect2,int n1,int n2)
    {
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++)  //Iterating over str1 from string length 1 to n1
        {
            for(int j=1;j<=n2;j++)  //Iterating over str2 from string length 1 to n2
            {
                if(vect1[i-1]==vect2[j-1])
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
    
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,bool> ma;
        for(auto x: target)
        {
            ma[x]=true;
        }
        vector<int> result;
        for(int i=0;i<arr.size();i++)
        {
            if(ma.find(arr[i])!=ma.end())  result.push_back(arr[i]);
        }
        int n1=target.size();
        int n2=result.size();
        
        int length=LCS(target,result,n1,n2);
        if(length<n1)  return n1-length;
        return 0;
    }
};