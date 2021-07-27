string LPS(string str)
{
    int n=str.length();
    vector<vector<bool>> dp(n,vector<bool>(n,false)); 
    int maxLen=0;
    string result;
    for(int w=1;w<=n;w++)   //w stands for window size 
    {
        // i will the index of starting item of window and i+w-1 will be index of last item of window making length= (i+w-1)-(i)+1= w
        for(int i=0;i+w-1<n;i++)  
        {
            if(w==1)   //Window of length 1 is always palindrome
            {
                dp[i][i+w-1]=true;
                if(w>maxLen)  //If current maxLen of the result is smaller than the w which is proven palindrome update result and maxLen
                {
                    result=str.substr(i,w);  //Extract the substring starting from index i of length w.
                    maxLen=w;
                }
            }
            else if(w==2 && str[i]==str[i+w-1])  //Window of length 2 is palidrome if given condition is met
            {
                dp[i][i+w-1]=true;
                if(w>maxLen)  //If current maxLen of the result is smaller than the w which is proven palindrome update result and maxLen
                {
                    result=str.substr(i,w);
                    maxLen=w;
                }
            }
            else
            {
                // checking if a#$%&a then #$%& is palindrome or not if first and last items are same
                if(str[i]==str[i+w-1] && dp[i+1][(i+w-1)-1]==true) 
                {
                    dp[i][i+w-1]=true;
                    if(w>maxLen) //If current maxLen of the result is smaller than the w which is proven palindrome update result and maxLen
                    {
                        result=str.substr(i,w);
                        maxLen=w;
                    }
                }
            }
        }
    }
    return result;
}