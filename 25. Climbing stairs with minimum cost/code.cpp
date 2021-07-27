// Minimum cost to reach the top of the floor by climbing stairs

// function to find the minimum cost 
// to reach N-th floor 
int minimumCost(vector<int> cost, int n) 
{ 
    // declare an array 
    vector<int> dp(n+1,0); 
  	cost.insert(cost.begin(),0); //Let us insert and assume that cost to reach to 0th floor is 0.
    // base case 
    if (n == 0) 
    {
    	return cost[0]; 
    }
  
    // initially to climb till 0-th 
    // or 1th stair 
    dp[0] = cost[0]; 
    dp[1] = cost[1]; 
  
    // iterate for finding the cost 
    for (int i = 2; i <= n; i++) { 
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]; 
    } 
  
    // return the minimum 
    return dp[n]; 
} 