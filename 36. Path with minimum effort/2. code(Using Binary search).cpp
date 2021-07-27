bool bfs(int cost,vector<vector<int>>& heights)
    {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>> visited(r,vector<int>(c,false));
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<int> dist={0,-1,0,1,0};
        int countNodes=0;

        while(1)
        {
            countNodes=q.size();
            if(countNodes==0)
            {
                break;
            }
            while(countNodes>0)
            {
                auto [currX,currY]=q.front();  //just one stepper for pair<int,int> curr=q.front() then currX=curr.first and currY=curr.second
                q.pop();

                //If we successfully made it to the destination with the minimum effort lesser than or equal to input 'cost' supplied then return true
                if(currX==r-1 && currY==c-1) 
                {
                    return true;
                }
                for(int d=0;d+1<5;d++)
                {
                    int nextX=currX + dist[d];
                    int nextY=currY + dist[d+1];
                    if(nextX<0 || nextX>=r || nextY<0 || nextY>=c)
                    {
                        continue;
                    }
                    //If we already visited to (nextX,nextY) then do not go there
                    else if(visited[nextX][nextY]==true)
                    {
                        continue;
                    }
                    //If we are reaching to the (nextX,nextY) from (currX,currY) with cost greater than input 'cost' then do not go there
                    else if(abs(heights[nextX][nextY] - heights[currX][currY])>cost) 
                    {
                        continue;
                    }

                    //Otherwize go there
                    q.push(make_pair(nextX,nextY));
                    visited[nextX][nextY]=true;
                }
                countNodes--;
            }
        }
        /*
            If we came out of the loop without reaching to (r-1,c-1) implies there is no path
            to reach to (r-1)(c-1) from (0,0) with minimum effort<=cost. So return false.
        */ 
        return false;
    }
    
int minimumEffortPath(vector<vector<int>>& heights) //Driver function
{
    
    int left=0;
    int right=1e6+1;
    while(left<right)
    {
        int mid=left+ (right-left)/2;  //mid= left + d/2;  where d is distance between left and right
        
        if(bfs(mid,heights)==true)  //this will recieve true if there exist a path to (r-1,c-1) from (0,0) with minimum effort less than or equal to mid or current cost.
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}