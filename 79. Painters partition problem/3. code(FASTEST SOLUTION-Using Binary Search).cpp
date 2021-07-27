#include<bits/stdc++.h>
using namespace std;

long long int find(vector<long long int> &board, long long int at_most) 
{ 
    long long int n = board.size();
    long long int s = 0, painters = 1; 
  
    for (int i = 0; i < n; i++) 
    { 
        s += board[i]; 
  
        if (s > at_most) 
        { 
            s = board[i]; //Reinitialize to current painters index
            painters++; 
        } 
    } 
  
    return painters; 
} 

long long int partition(vector<long long int> &board, int k) 
{ 
    long long int n = board.size();
    long long int low=INT_MIN,high=0;
    for(int i = 0; i < n; i++)
    {
        low=max(low,board[i]);
        high += board[i];
    }
    
    while (low <= high) 
    { 
        long long int mid = low + (high - low) / 2; 
        long long int readers = find(board, mid); 
  
        if (readers <= k) 
        {
            high = mid-1;
        }
        else 
        {
            low = mid + 1; 
        }
    } 
    return low; 
} 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long int> vect(n);
        for(int i=0;i<n;i++)
        {
            cin>>vect[i];
        }
        int k;
        cin>>k;
        
        if(k>n)
        {
            cout<<-1<<"\n";
            continue;
        }
        
        
        long long int count=partition(vect,k);
        cout<<count<<"\n";
    }
    return 0;
}