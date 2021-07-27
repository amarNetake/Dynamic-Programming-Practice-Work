/*
	For the first subproblem, the solution is to accumulate the sum of each row between columns l and r.
	Then, we can use the Kadane's algorithm to find the maximum sum subarray for all those columns. Search for the
	Maximum Sum Rectangle problem on Youtube for video explanations.
	
	Now, we are not looking for just the maximum sum, but maximum sum less than k. You may be tempted to try a 
	sliding window technique here, but the problem is that we can have negative numbers. For problem #560, we 
	used a hash set to find a sum that equals to k. Here, we can use an ordered set and binary-search for a complement value.

	However, the most noticeable optimization is to go back to the Kadane's algorithm! We can compute the maximum 
	rectangle sum in O(n). If the maximum sum rectangle sum is less or equal than k, we can skip the binary search 
	phase completely. This improves the runtime from 800 ms to 50 ms.
*/

class Solution {
public:
        int maxSumSubmatrix(vector<vector<int>>& m, int k) {
        int res = INT_MIN, rows = m.size(), cols = m[0].size();
        for (int l = 0; l < cols; ++l) {
            vector<int> sums(rows);
            for (int r = l; r < cols; ++r) {
                int kadane = 0, max_kadane = INT_MIN;
                for (int i = 0; i < rows; ++i) {
                    sums[i] += m[i][r];
                    kadane = max(kadane + sums[i], sums[i]);
                    max_kadane = max(max_kadane, kadane);
                }
                if (max_kadane <= k) {
                    res = max(res, max_kadane);
                    continue;
                }
                set<int> s = {0};
                int run_sum = 0;
                for (int sum : sums) {
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if (it != end(s))
                        res = max(res, run_sum - *it);
                    s.insert(run_sum);
                }
            }
        }
        return res;
    } 
};