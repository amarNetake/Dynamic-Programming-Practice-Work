class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        
        int n=costs.size();
        if(n==0) return 0;
        int m=costs[0].size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                costs[i-1][j]=costs[i-1][j]+1000000; //Just to ensure this color does not get counted in the pervious house
                costs[i][j]=costs[i][j]+  *min_element(costs[i-1].begin(),costs[i-1].end());
                costs[i-1][j]=costs[i-1][j]-1000000;
            }
        }
        return *min_element(costs[n-1].begin(),costs[n-1].end());
    }
};