class Solution {
public:
    int playGame(vector<int>& piles,int curr,int n,vector<vector<int>>& dp,int m)
    {
        if(curr>=n) return 0;
        if(dp[curr][m]!=-1e8) return dp[curr][m];
        int sum=0;
        for(int i=0;i<2*m;i++)
        {
            if(curr+i<n) sum=sum+piles[curr+i];
            
            dp[curr][m]=max(dp[curr][m],sum-playGame(piles,curr+i+1,n,dp,max(m,i+1)));
        }
        return dp[curr][m];
    }
    
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(200,vector<int>(300,-1e8));
        int total=0;
        for(auto x: piles) total=total+x;
        int m=1;
        int diff=playGame(piles,0,n,dp,m);
        /*
            Let x be the score of Alice.
            x+(x-diff)=total => x=(total+diff)/2
        */
        return (total+diff)/2;
    }
};