int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        
        vector<vector<int>> dp(r,vector<int>(c,10000000));  //dp[i][j] will store the optimal path to reach to (i,j) from (0,0)
        dp[0][0]=0;

        /*
        	Since we can move in 4 directions, it has circular reference. We need to traverse entire 'dp' for atleast r*c times, to
        	make sure the optimal solution gets populated in the target location.
        */
        for(int k=0;k<r*c;k++)  
        {
        	//It not a single change happened in the current iteration implies the dp is optimized so break.
        	//So to keep track of that we keep 'stable' pointer. We turn stable=false if atleast one field of 'dp' is altered.
        	//At the end if stable is false we continue else break;
            bool status=true; 

            vector<int> dist={0,-1,0,1,0}; //(x+dist[i],y+dist[i+1]) will give left,top,bottom,right to get from which node we reached here 
            for(int x=0;x<r;x++)
            {
                for(int y=0;y<c;y++)
                { 
                    for(int d=0;d+1<5;d++)
                    {
                        int prevX=x+dist[d];       
                        int prevY=y+dist[d+1];
                        if(prevX<0||prevX>=r||prevY<0||prevY>=c)
                        {
                            continue;
                        }
                        int optimal=max(dp[prevX][prevY],abs(heights[x][y]-heights[prevX][prevY])); 
                        if(optimal<dp[x][y])
                        {
                            dp[x][y]=optimal;
                            status=false;
                        }
                    }
                }
            }
            if(status==true)
            {
                break;
            }
        }
        return dp[r-1][c-1];
    }