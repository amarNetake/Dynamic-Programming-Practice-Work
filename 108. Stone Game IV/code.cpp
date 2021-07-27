class Solution {
public:
    
    int playGame(int n,vector<int>& dp)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int result=0;
        for(int i=1;i*i<=n;i++)
        {
            //If the opponent won the game then surely current player will lose and vice versa
            //So result of current player= NOT(playGame())=> In integer format we can negate it by subtracting the
            //result from 1
            result=result + (1-playGame(n-i*i,dp)); 
            if(result==1) return dp[n]=result; //If player win in any of the scenario(for any i) then he can definately win
        }
        return dp[n]=result;
    }
    
    bool winnerSquareGame(int n) {
        vector<int> dp(1e6,-1); //0->false; 1->true ; true->if player wins the game
        int result=playGame(n,dp);
        return result==1?true:false;
    }
};