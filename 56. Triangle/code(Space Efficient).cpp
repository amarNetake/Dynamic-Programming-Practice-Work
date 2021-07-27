/*
        Time complexity:- O(n^2)
        Space complexity:- O(1)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        /*
                Since it is a triangle every ith row has i elements or ith row will have i columns
                Then we can say that maximum number of elements in any row= Number of rows
        */

        /*
            We are going to make the changes in the existing triangle 2-D vector itself by making it to hold the minimum path from
            0th row till that element
        */
        
        int n=triangle.size();
        
        if(n==1) return triangle[0][0];
        
        int result=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)   //Since ith row is bound to have i elements
            {
                if(i==0&&j==0)  continue;
                else if(j==0)   triangle[i][j]=triangle[i][j] + triangle[i-1][j];
                else if(j==i)   triangle[i][j]=triangle[i][j] + triangle[i-1][j-1];
                else triangle[i][j]=triangle[i][j] + min(triangle[i-1][j-1],triangle[i-1][j]);
                
                if(i==n-1)   result=min(result,triangle[i][j]);
            }
        }
        return result;
    }
};