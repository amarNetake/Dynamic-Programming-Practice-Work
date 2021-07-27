int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n=envelopes.size();
        auto cmp= [](vector<int> a,vector<int> b){          //Comparator function( if this return true then a and b will be swapped)
            if(a[0]==b[0])  return a[1]>b[1];  //Sort width in ascending order and if widths are same then sort heights in descending order
            return a[0]<b[0];
        };
        
        /*
        	Let us say we had envelopes as [[5,4],[6,5],[6,7],[2,3]] where [width, height] order
        	Now we will sort it on the basis of width in increasing order so that every ith envelope will be fittable in (i+k)th envelope as
        	far as width is considered. But we are wishing to reduce it to the problem of 1-D from 2-D envelopes array that is we will form
        	a heights array such that the LIS of heights array should yield the result we are looking for. 
        	for that we have 2 options:
        	sort1: [2,3]->[5,4]->[6,5]->[6,7]
        	sort2: [2,3]->[5,4]->[6,7]->[6,5]

        	Now the problem with sort1 is that if we sort the heights also in increasing order and then yield out the height part to form 
        	heights array we will get [2,3,5,7] and the length of LIS will be 4 but we know that [6,5] will not fit in [6,7] as the condition
        	is width[i] < width[i+k] && height[i] < height[i+k]. Now here in heights array 5 is coming before 7 so LIS ending at 7 will be 
        	yielded as 2,3,5,7 but since 5 and 7 has same width that is 6 hence [6,5] cannot fit in [6,7] and vice versa. So we need to design
        	the array such that if width of 2 envelopes are same implies they cannot fit in one another so make sure that heights of such 
        	boxes are sorted in descending order. This will yield heights array [3,4,7,5] So not the LIS yielded will be 3,4,7 or 3,4,5 that 
        	is of length 3 which is the result we are looking for.
        */
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        //Now we will yield the height part in 1-D array and find the LIS of it.
        vector<int> heights;
        for(auto x: envelopes)
        {
            heights.push_back(x[1]);
        }
        
        vector<int> dp;  //Note that the size of dp is not initialized
        

        // This is the O(nlogn) approach as dp array will always be sorted
        for(int i=0;i<n;i++)
        {
            int curr=heights[i];
            int left=0,right=dp.size();  //Note that we are performing the binary search on dp array.
            while(left<right)
            {
                int mid=left+(right-left)/2;
                if(dp[mid]<curr)   //Note that comparision is done with the elements of dp array
                {
                    left=mid+1;
                }
                else
                {
                    right=mid;
                }
            }
            if(right>=dp.size())
            {
                dp.push_back(curr);
            }
            else
            {
                dp[right]=curr;
            }
        }
        return dp.size();
    }