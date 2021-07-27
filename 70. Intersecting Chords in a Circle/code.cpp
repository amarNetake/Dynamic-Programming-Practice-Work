// Basically number of ways to draw n non-intersecting chords in the circle is equal to nth catalan number

int Solution::chordCnt(int n) {
    
    vector<long int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int x=0,y=i-1;x<i;x++,y--)
        {
            dp[i]=(dp[i] + (dp[x]*dp[y]))%1000000007;
        }
    }
    return dp[n]%1000000007;
}
