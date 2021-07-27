#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> bridges(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        cin>>bridges[i][0]>>bridges[i][1];
    }
    sort(bridges.begin(),bridges.end());
    
    vector<int> lis(n,1);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(bridges[j][1] < bridges[i][1] && lis[i] < lis[j] + 1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    
    int maxCount=0;
    for(int i=0;i<n;i++)
    {
        maxCount=max(maxCount,lis[i]);
    }
    cout<<maxCount;
    return 0;
}