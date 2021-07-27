//This is a variation of longest increasing subsequence problem

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<vector<int>> config;
    
    for(int i=0;i<n;i++)
    {
    	/*
			For a particular box we are taking out all the possible ways we can treat its dimensions and use it
			We will treat the config[i][0] as length
			We will treat the config[i][1] as width
			We will treat the config[i][2] as height
    	*/
        config.push_back({height[i],width[i],length[i]});  
        config.push_back({height[i],length[i],width[i]});
        config.push_back({width[i],length[i],height[i]});
        config.push_back({width[i],height[i],length[i]});
        config.push_back({length[i],width[i],height[i]});
        config.push_back({length[i],height[i],width[i]});
    }
    
    //Sort all the configurations in descending order
    sort(config.begin(),config.end());  
    reverse(config.begin(),config.end());
    
    
    vector<int> msis(config.size());
    
    //Considering the single box or each box individually in it's variety of dimension perception
    //the maxHeight will be height of the box itself
    for(int i=0;i<config.size();i++)
    {
        msis[i]=config[i][2];
    }
    
    for(int i=1;i<config.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            /*
            	If the length and breadth of lower box is greater than that of current box and the maxHeight through jth box ending at
            	ith box is yielding more height than the current maxHeight till ith box then that subsequence shall be considered
            	Note:- THIS QUESTION CARES ABOUT THE DIMENSIONS of BASE RECTANGLE AND IS MORE STRICTER. THERE COULD BE ANOTHER VARIATION OF
            	 	   THE SAME QUESTION WHERE WE JUST CARE ABOUT THE BASE RECTANGLE AREA INSTEAD OF BASE RECTANGLE WIDTH AND LENGTH. 
            	 	   IN THAT CASE JUST COMPARE
            	config[j][0]*config[j][1] > config[i][0]*config[i][1] && msis[i] < msis[j] + config[i][2]
            */
            if(config[j][0]>config[i][0] && config[j][1]>config[i][1]  && msis[i] < msis[j] + config[i][2])
            {
                msis[i] = msis[j] + config[i][2];
            }
        }
    }
    
    int maxHeight=INT_MIN;
    for(int i=0;i<msis.size();i++)
    {
        maxHeight=max(maxHeight,msis[i]);
    }
    return maxHeight;
    
}