class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size()==1)
        {
            return triangle[0][0];
        }
        int result=INT_MAX;
        vector<vector<int>> dp;
        int r=triangle.size();
        dp.push_back({triangle[0][0]});
        for(int i=1;i<r;i++)
        {
            vector<int> temp;
            int c=triangle[i].size();
            for(int j=0;j<c;j++)
            {
                int curr;
                int num1=INT_MAX,num2;
                num1= j==0?INT_MAX:dp[i-1][j-1];
                num2= j==c-1?INT_MAX:dp[i-1][j];
                curr= min(num1,num2) + triangle[i][j];
                if(i==r-1)
                {
                    result=min(result,curr);
                }
                temp.push_back(curr);
            }
            dp.push_back(temp);
        }
        for(int i=0;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return result;
    }
};