#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin>>n;
    vector<long long int> vect(n);
    set<long long int> s;
    long long int count=0,sum=0;
    s.insert(0);
    for(int i=0;i<n;i++)
    {
        cin>>vect[i];
        sum=sum+vect[i];
        if(s.count(sum))
        {
            count++;
            s.clear();
            s.insert(0);
            s.insert(vect[i]);
            sum=vect[i];
        }
        else
        {
            s.insert(sum);
        }
    }
    cout<<count;
}