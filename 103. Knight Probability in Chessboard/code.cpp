class Solution {
public:
    vector<vector<int>> disp = {{-2,-1},{-2,1},{-1,-2},{-1,2},{2,-1},{2,1},{1,-2},{1,2}};
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n,vector<double>(n,0));
        vector<vector<double>> next(n,vector<double>(n,0));
        vector<vector<double>> temp(n,vector<double>(n,0));
        curr[row][column]=1.0;
        for(int moves=0;moves<k;moves++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(curr[i][j]!=0)
                    {
                        for(auto x:disp)
                        {
                            int dx=i+x[0];
                            int dy=j+x[1];
                            if(dx>=0 && dx<n && dy>=0 && dy<n) next[dx][dy]=next[dx][dy] + (double)curr[i][j]/8; 
                        }
                    }
                }
            }
            curr=next;
            next=temp; //Basically we cleared next
        }
        double totalProb=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                totalProb=totalProb + curr[i][j];
            }
        }
        return totalProb;
    }
};