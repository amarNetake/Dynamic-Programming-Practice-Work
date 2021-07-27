// Kadane's algorithm variant
int maxSubstring(string str)
	{
	    // Your code goes here
	    
	    int maxEndingHere=0;
	    int maxSoFar=0;
	    if(str[0]=='1')
	    {
	        maxEndingHere=-1;
	        maxSoFar=-1;
	    }
	    else
	    {
	        maxEndingHere=1;
	        maxSoFar=1;
	    }
	    
	    for(int i=1;i<str.length();i++)
	    {
	        if(str[i]=='1')
	        {
	            maxEndingHere=max(maxEndingHere-1,-1);
	            maxSoFar=max(maxSoFar,maxEndingHere);
	        }
	        else
	        {
	            maxEndingHere=max(maxEndingHere+1,1);
	            maxSoFar=max(maxSoFar,maxEndingHere);
	        }
	    }
	    return maxSoFar;
	}