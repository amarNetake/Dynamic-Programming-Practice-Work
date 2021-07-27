class Solution {
public:
    
    //This part is same as maxArea of Histogram
    int findArea(vector<int>& heights)
    {
        int n=heights.size();
        vector<int> leftLimit(n,0);
        vector<int> rightLimit(n,0);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(s.empty()==false && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            if(s.empty()==true) leftLimit[i]=0;
            else leftLimit[i]=s.top()+1;
            
            s.push(i);
        }
        
        while(s.empty()==false) s.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(s.empty()==false && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            
            if(s.empty()==true) rightLimit[i]=n-1;
            else rightLimit[i]=s.top()-1;
            
            s.push(i);
        }
        int Area=0;
        for(int i=0;i<n;i++)
        {
            Area=max(Area,(rightLimit[i]-leftLimit[i]+1)*heights[i]);
        }
        return Area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix)  //Driver function
    {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        vector<int> heights(m,0);  //For each row => number of elements in each row =number of columns
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0') heights[j]=0; //Longest consecutive 1's along jth column ending at ith row and jth column
                else heights[j]= heights[j] + (matrix[i][j]-'0');
            }
            int area=findArea(heights);
            if(area>maxArea) maxArea=area;
        }
        return maxArea;
    }
};