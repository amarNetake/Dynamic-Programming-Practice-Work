int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<int> lis(intervals.size(),1);
        
        for(int i=1;i<lis.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(intervals[j][1]<=intervals[i][0] && lis[i] < lis[j]+1)
                {
                    lis[i]=lis[j]+1;
                }
            }
        }
        
        int maxCount=0;
        for(int i=0;i<lis.size();i++)
        {
            maxCount=max(maxCount,lis[i]);
        }
        return lis.size()-maxCount;
    }