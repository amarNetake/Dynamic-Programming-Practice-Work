#include <bits/stdc++.h>
using namespace std;

int maximizetip(vector<int>& rahul,vector<int>& ankit,int x,int y,int n)
{
    int totaltip=0;
    vector<vector<int>> finaltips(n,vector<int>(3)); //This array will hold vectors of size 3 which will denote {diff,rahul tip,ankit tip}
    for(int i=0;i<n;i++)
    {
        finaltips.push_back({ abs(rahul[i]-ankit[i]), rahul[i], ankit[i] });
    }
    
    //Sort the finaltips in decreasing order as we want to ensure to take the larger element when the difference between two tips is large
    sort(finaltips.begin(),finaltips.end());
    reverse(finaltips.begin(),finaltips.end());
    for(int i=0;i<n;i++)
    {
        if(x>0 && y>0)
        {
            if(finaltips[i][1]>=finaltips[i][2])
            {
                totaltip=totaltip + finaltips[i][1]; //tip of rahul got added
                x--;
            }
            else
            {
                totaltip=totaltip + finaltips[i][2];  //tip of ankit got added
                y--;
            }
        }
        else if(x==0)
        {
            totaltip=totaltip + finaltips[i][2];  //tip of ankit got added
            y--;
        }
        else
        {
            totaltip=totaltip + finaltips[i][1]; //tip of rahul got added
            x--;
        }
    }
    return totaltip;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,y;
	    cin>>n>>x>>y;
	    vector<int> rahul(n);
	    vector<int> ankit(n);
	    for(auto& it:rahul)
	    {
	        cin>>it;
	    }
	    for(auto& it: ankit)
	    {
	        cin>>it;
	    }
	    int tip=maximizetip(rahul,ankit,x,y,n);
	    cout<<tip<<"\n";
	}
	return 0;
}