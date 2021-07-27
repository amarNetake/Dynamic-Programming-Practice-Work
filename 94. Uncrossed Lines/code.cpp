class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int r=A.size();
        int c=B.size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        A.insert(A.begin(),0);
        B.insert(B.begin(),0);
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(A[i]==B[j]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[r][c];
    }
};