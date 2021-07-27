class Solution {
public:
    
    vector<int> freq(string s)
    {
        vector<int> freq(26,0);
        for(auto x: s)
        {
            freq[x-'a']++;
        }
        return freq;
    }
    
    bool isScramble(string s1, string s2) {
        
        int n=s1.length();
        if(s1==s2)  return true;
        if(freq(s1)!=freq(s2))  return false;
        //Since we need to ensure the length of two partitions has to be non empty we need to 
        // run the bp=1 to bp=n-1 so that s=x|y such that 1<=x.length<=n-1 && 1<=y<=n-1
        //Hence we need to run bp(breakpoint) from 1 to n-1
        for(int bp=1;bp<n;bp++)
        {
            bool caseA1= isScramble(s1.substr(0,bp),s2.substr(0,bp)); 
            bool caseA2= isScramble(s1.substr(bp),s2.substr(bp));
            bool caseB1= isScramble(s1.substr(0,bp),s2.substr(n-bp));
            bool caseB2= isScramble(s1.substr(bp),s2.substr(0,n-bp));
            
            
            // We are having s1= x|y and s2=m|n  .We are trying scramble on (x,m)&&(y,n)  OR (x,n)&&(y,m) for all the breakpoints possible
            if((caseA1&&caseA2)||(caseB1&&caseB2))  return true;
            
        }
        return false;
    }
};