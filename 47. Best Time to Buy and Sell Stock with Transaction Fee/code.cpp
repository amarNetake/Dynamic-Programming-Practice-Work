class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==0)  return 0;
        vector<int> bs(n,0);  // bought state: bi->sj->.....->bk->sk 
        vector<int> ss(n,0);  // sold state: bi->sj->.....->bk->sk
        bs[0]=-1*prices[0];
        ss[0]=0;
        for(int i=1;i<n;i++)
        {
            bs[i]=max(bs[i-1],ss[i-1]-prices[i]);
            ss[i]=max(ss[i-1],prices[i]+bs[i]-fee);  //Since bs is by default negative on loss then we can simply add
        }
        return ss[n-1];
    }
};