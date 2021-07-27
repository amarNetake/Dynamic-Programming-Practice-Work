#include <bits/stdc++.h>
using namespace std;

int largestArea(vector<int>& vect)
{
    vect.push_back(0);
    stack<int> s;
    int maxArea=0;
    int area;
    for(int i=0;i<vect.size();i++)
    {
        if(s.empty()==true)
        {
            s.push(i);
        }
        else if(vect[s.top()]<=vect[i])
        {
            s.push(i);
        }
        else if(vect[s.top()]>vect[i])
        {
            while(s.empty()==false&&vect[s.top()]>vect[i])
            {
                int firstBlock=s.top();
                s.pop();
                if(s.empty()==true)
                {
                    area=vect[firstBlock]*i;
                }
                else
                {
                    area=vect[firstBlock]*(i-s.top()-1);
                }
                if(area>maxArea)
                {
                    maxArea=area;
                }
            }
            s.push(i);
        }
    }
    vect.pop_back();
    return maxArea;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> vect(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>vect[i];
	    }
	    int maxArea=largestArea(vect);
	    cout<<maxArea<<"\n";
	}
	return 0;
}