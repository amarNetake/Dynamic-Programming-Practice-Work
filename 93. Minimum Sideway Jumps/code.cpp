class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> top(n,0);
        vector<int> mid(n,0);
        vector<int> bot(n,0);
        for(int i=n-2;i>=0;i--)
        {
            if(obstacles[i]==1) top[i]=1e8;
            else if(obstacles[i]==2) mid[i]=1e8;
            else if(obstacles[i]==3) bot[i]=1e8;
            
            int TOP=top[i]==1e8?1e8:top[i+1];
            int MID=mid[i]==1e8?1e8:mid[i+1];
            int BOT=bot[i]==1e8?1e8:bot[i+1];
            if(top[i]!=1e8)
            {
                top[i]=min({top[i+1],MID+1,BOT+1});
            }
            if(mid[i]!=1e8)
            {
                mid[i]=min({mid[i+1],TOP+1,BOT+1});
            }
            if(bot[i]!=1e8)
            {
                bot[i]=min({bot[i+1],TOP+1,MID+1});
            }
        }
        return mid[0];
    }
};