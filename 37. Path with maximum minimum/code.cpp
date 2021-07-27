int maximumMinimumPath(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<int>> dp(r,vector<int>(c,-100000000));  //dp[i][j] will store the maximum of all minimums from (0,0) till (i,j)
        dp[0][0]=grid[0][0];
        vector<int> dist={0,-1,0,1,0};
        /* Because it has circular reference(top,bottom,left,right) we need to check for traverse through 'dp' atleast r*c times. */
        for(int k=0;k<r*c;k++)
        {
            bool stable=true;
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
                        /*
                                dp[prevX][prevY] contains the maximum minimum till (prevX,prevY) from (0,0) now if we come to (x,y) from (prevX,prevY) then
                                minimum till (x,y) will be min(dp[prevX][prevY],grid[x][y]) and then compare it with previous maximum minimum at (x,y) if new
                                minimum found is larger than previous minimum then dp[x][y]=new maximum minimum.
                        */
                        int optimal=min(dp[prevX][prevY],grid[x][y]);  
                        if(optimal>dp[x][y])
                        {
                            dp[x][y]=optimal;
                            stable=false;
                        }
                    }
                }
            }
            if(stable==true)
            {
                break;
            }
        }
        return dp[r-1][c-1];
    }