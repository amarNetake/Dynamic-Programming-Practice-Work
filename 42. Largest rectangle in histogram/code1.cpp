int largestRectangleArea(vector<int>& heights) 
{
    //To ensure all the items till the last item is processed successfully and at the
    //end when we process the last item we process all the items in the stack until it
    //becomes empty we push extra 0 to the end of heights vector.
    heights.push_back(0); 
    int maxArea=0;
    int area;
    stack<int> s;
    int i;
    for(i=0;i<heights.size();i++)
    {
        if(s.empty()==true)
        {
            s.push(i);
            continue;
        }
        else if(heights[s.top()]<=heights[i])
        {
            s.push(i);
            continue;
        }
        else if(heights[s.top()]>heights[i])
        {
            while(s.empty()==false&&heights[s.top()]>heights[i])
            {
                int startBlock=s.top();
                s.pop();
                if(s.empty()==true)
                {
                    area=heights[startBlock]*i;
                }
                else
                {
                    area=heights[startBlock]*(i-s.top()-1);
                }
                if(maxArea<area)
                {
                    maxArea=area;
                }
            }
            s.push(i);
        }
    }
    heights.pop_back();  //Pop the pushed extra zero
    return maxArea;
}