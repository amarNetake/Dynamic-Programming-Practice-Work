class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> schedule;
        for(int i=0;i<n;i++)
        {
            schedule.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(schedule.begin(),schedule.end());  //Sorted it by endTime
        vector<int> dp(n);
        int maxProfit=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=schedule[i][2];
            maxProfit=max(maxProfit,dp[i]);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(schedule[i][1]>=schedule[j][0] && dp[i]<dp[j]+schedule[i][2])
                {
                    dp[i]=dp[j]+schedule[i][2];
                    maxProfit=max(maxProfit,dp[i]);
                }
                else if(dp[i] >= dp[j]+schedule[i][2])  continue;
                else break;
            }
        }
        return maxProfit;
    }
};