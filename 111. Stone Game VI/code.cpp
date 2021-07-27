class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n=alice.size();
        vector<int> total(n,0);
        for(int i=0;i<n;i++) total[i]=alice[i]+bob[i];
        vector<vector<int>> vect(n);
        for(int i=0;i<n;i++) vect[i]={total[i],alice[i],bob[i]};
        sort(vect.begin(),vect.end(),greater<vector<int>>());
        int aliceScore=0,bobScore=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) aliceScore=aliceScore+vect[i][1];
            else bobScore=bobScore+vect[i][2];
        }
        if(aliceScore>bobScore) return 1;
        else if(bobScore>aliceScore) return -1;
        else return 0;
    }
};