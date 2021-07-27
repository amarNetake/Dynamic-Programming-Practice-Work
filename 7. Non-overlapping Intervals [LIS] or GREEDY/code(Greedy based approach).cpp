class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int n=intervals.size();
        int count=0;
        int left=0,right=1;
        while(right<n)
        {
            if(intervals[left][1]<=intervals[right][0])  //Safe state
            {
                left=right;
                right++;
            }
            else if(intervals[left][1]>= intervals[right][1])    //right interval completely inside left interval
            {
                left=right;    //Deleted the item pointed by left
                right+=1;
                count++;
            }
            else    //Right interval partially inside left interval
            {
                right=right+1;   //Deleted the item pointed by right
                count+=1;
            }
        }
        return count;
    }
};