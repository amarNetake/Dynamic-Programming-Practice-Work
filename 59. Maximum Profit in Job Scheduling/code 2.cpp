class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> task;
        int n=startTime.size();
        for(int i=0;i<n;i++)
        {
            task.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(task.begin(),task.end());
        map<int,int> ma;    //endTime->profit
        
        //ma.upper_bound(x)-Gives first iterator with key larger than x
        //prev(itr)= iterator prev to pointed by iterator itr
        //next(itr)= iterator next to pointed by iterator itr
        
        //Thus prev(ma.upper_bound(x)) will give the first iterator with key just immediately smaller than x
        // '->' to access item through iterator and '.' is used otherwise
        ma[0]=0;
        for(auto x: task)
        {
        	//Find the iterator 'itr' of ma whose endTime is immediately greater than start time of current task x
        	// then taking prev(itr) will yield the possible sequence of tasks it can get attached to.
        	//We have basically being performing binary search
            int curr=prev(ma.upper_bound(x[1]))->second + x[2];//curr will be storing the profit after appending the current task to it's possible previous
            if(curr > ma.rbegin()->second)
            {
                ma[x[0]]=curr;
            }
        }
        return ma.rbegin()->second;
    }
};

/*
		Sort the jobs by endTime.

		dp[k] = p means that within the first k time duration,
		we cam make at most 'p' profit money.
		Intial dp[0] = 0, as we make profit = 0 at time = 0.
		
		For each job = [s, e, p], where s,e,p are its start time, end time and profit,
		Then the logic is similar to the knapsack problem.
		If we don't do this job, nothing will be changed.
		If we do this job, binary search in the dp to find the largest profit we can make before start time s.
		So we also know the maximum cuurent profit that we can make doing this job.
		
		Compare with last element in the dp,
		we make more money,
		it worth doing this job,
		then we add the pair of [e, cur] to the back of dp.
		Otherwise, we'd like not to do this job.
*/