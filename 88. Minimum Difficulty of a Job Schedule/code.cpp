class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        jobDifficulty.insert(jobDifficulty.begin(),1e7);
        vector<vector<int>> dp(n+1,vector<int>(d+1,1e7));
        dp[0][0]=0;
        // dp[i][j] = Minimum difficulty to schedule i jobs in j days
        
        for(int i=1;i<=n;i++)  
        {
            /*
                Since days should be less than equal to jobs to be able to schedule i jobs in j days such
                that you have atleast one job each day.
            */
            for(int j=1;j<=min(i,d);j++)  
            {
                int md=jobDifficulty[i];
                /*
                    dp[i][j] = min(To schedule 1 to k-1 jobs in j-1 days and k to i jobs in last day) 
                    for all k > j-1
                    as you need atleast j-1 jobs to schedule in j-1 days and rest of jobs you can schedule in                       last day.
                */
                for(int k=i;k>=j;k--)
                {
                    md=max(md,jobDifficulty[k]);
                    dp[i][j]=min(dp[i][j],dp[k-1][j-1]+md);
                }
            }
        }
        
        return dp[n][d];
    }
};