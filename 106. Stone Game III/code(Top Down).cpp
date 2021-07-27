class Solution {
public:
    
    int playGame(vector<int>& stoneValue,vector<int>& dp,int n,int curr)
    {
        if(curr>=n) return 0;
        if(dp[curr]!=INT_MIN) return dp[curr];
        int sum=0;
        for(int i=curr;i<=curr+2 && i<n;i++)
        {
            sum=sum+stoneValue[i];
            dp[curr]=max(dp[curr],sum - playGame(stoneValue,dp,n,i+1));
        }
        return dp[curr];
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,INT_MIN); //dp[i]-> Will store the difference of scores of current player's score and it's opponents score if current player has turn and he plays from index i onwards
        int diff=playGame(stoneValue,dp,n,0);
        if(diff>0) return "Alice";
        else if(diff==0) return "Tie";
        else return "Bob";
    }
};