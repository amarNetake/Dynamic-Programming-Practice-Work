class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int> bs(n);
        vector<int> ss(n);
        vector<int> cs(n);
        bs[0]=-1*prices[0];
        ss[0]=0;
        cs[0]=0;
        for(int i=1;i<n;i++)
        {
            bs[i]=max(bs[i-1],cs[i-1]-prices[i]);
            ss[i]=max(ss[i-1],prices[i]+bs[i-1]);  //We will add as loss is already maintained as sign in bs
            cs[i]=max(cs[i-1],ss[i-1]);
        }
        return max(ss[n-1],cs[n-1]);
    }
};