bool increasingTriplet(vector<int>& nums) 
{
        
    int n1=INT_MAX;  // n1 will be holding the smallest of all 3 numbers
    int n2=INT_MAX;  // n2 will be holding the 2nd smallest number
    //Then if we found the number that is greater than both n1 and n2 then we will declare their exist Increasing triplet subsequence
    for(int x:nums)
    {
        if(x < n1)  //Since n1 should hold the smallest value hence if x comes out to be smaller than n1 then n1 should be assigned x
        {
            n1=x;
        }
        else if(x < n2 && x>n1) //If x is greater than n1 but less than n2 implies n2 should become x
        {
            n2=x;
        }
        else if(x>n1 && x>n2)  //If x is greater than both n1 and n2 implies we found the Increasing triplet subsequence
        {
            return true;
        }
    }
    return false;
}