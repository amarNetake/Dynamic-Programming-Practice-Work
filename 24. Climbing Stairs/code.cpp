// Similar question to "Decode ways problem"
int climbStairs(int n) {
    if(n<2)
    {
        return 1;
    }
    vector<int> dp(n+1,0);
    dp[0]=1;  //Number of ways to jump from 0th floor to 0th floor
    dp[1]=1;  //Number of ways to jump from 0th floor to 1st floor
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];   
    }
    return dp[n];
}

/*

Current stair can be reached through:-
0 ->"0" => 1 ways => dp[0]=1
1 ->"01" => 1 ways => dp[1]=1
2 ->"02","012" -> 2 ways =>Note that we can append 2 or say we can jump to 2 from 0 or from 1 hence total distinct strings till 2= dp[0]+dp[1]
3 ->"013","023","0123" => Appended 3 to possible reaches till 1 and 2 to get possible reaches till 3.=> dp[3]=dp[1]+dp[2]
4 ->"024","0124","0134","0234","01234" => dp[4]=dp[2]+ dp[3]
.
.
.

*/