//Using "binary search" + dp approach  ---> O(nlogn) approach

/*
	dp :[2 5 7 12 14 17]   and vect[i]=9 then we will look for the item in dp which is immediately greater than 9 and replace it with 9
		 F F F T  T  T  replace the first True with 9. So here we replace 12 with 9
		 	So the dp will become dp: [2 5 7 9 14 17]

	dp :[2 5 6 8] and we are given vect[i]=9 then as we can see all the items of dp are smaller than 9 so "append" 9 to the end of dp
		 F F F F    
			So dp will become : [2 5 6 8 9]
*/

int longestSubsequence(int n, int vect[])
{
   // your code here
   vector<int> dp;  //initialized dp with size 0
   for(int i=0;i<n;i++)
   {
       int left=0,right=dp.size();
       while(left<right)
       {
           int mid=left+(right-left)/2;
           
           //At the end where right pointer will be pointing shall be the index where current item shall be inserted
           
           if(dp[mid]>=vect[i]) //Since we are looking for strictly greater so need to consider for replacement the equal item as well
           {
               right=mid;    //This could be the potential solution but better solution may exist in left of mid pointer
           }
           else
           {
               left=mid+1;
           }
       }
       if(right==dp.size())  //No item found greater than vect[i] so it shall be appended 
       {
           dp.push_back(vect[i]);
       }
       else   //dp[right] shall be best suited with the vect[i] as vect[i] is immediate smaller than current dp[right].
       {
       	   //(Being greedy to put lowest item) as in future this will help to build the dp array to be LIS
           dp[right]=vect[i];
       }
   }
   
   return dp.size();
}