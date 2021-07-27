#include <bits/stdc++.h>
using namespace std;

int booleanParenthesization(string booleans,string operators)
{
    int n=booleans.length();
    vector<vector<int>> dpt(n,vector<int>(n,0));  //This will store total ways to parenthesize such that the substring will generate True
    vector<vector<int>> dpf(n,vector<int>(n,0));  //This will store total ways to parenthesize such that the substring will generate False
    //dpt[i][j]=>total ways to generate true for substring under considereation
    //dpf[i][j]=>total ways to generate false for substring under considereation
    for(int i=0;i<n;i++)
    {
        if(booleans[i]=='T')
        {
            dpt[i][i]=1;
            dpf[i][i]=0;
        }
        else
        {
            dpt[i][i]=0;
            dpf[i][i]=1;
        }
    }
    
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j+i<n;j++)
        {
            int k=0;
            int totalT=0;
            int totalF=0;
            while(j+k<j+i)
            {
                if(operators[j+k]=='&')
                {
                    totalT= totalT + dpt[j][j+k]*dpt[j+k+1][j+i];
                    totalF= totalF + dpt[j][j+k]*dpf[j+k+1][j+i] + dpf[j][j+k]*dpt[j+k+1][j+i] + dpf[j][j+k]*dpf[j+k+1][j+i];
                }
                else if(operators[j+k]=='|')
                {
                    totalT= totalT + dpt[j][j+k]*dpt[j+k+1][j+i] + dpt[j][j+k]*dpf[j+k+1][j+i] + dpf[j][j+k]*dpt[j+k+1][j+i];
                    totalF= totalF + dpf[j][j+k]*dpf[j+k+1][j+i];
                }
                else if(operators[j+k]=='^')
                {
                    totalT= totalT + dpt[j][j+k]*dpf[j+k+1][j+i] + dpf[j][j+k]*dpt[j+k+1][j+i];
                    totalF= totalF + dpt[j][j+k]*dpt[j+k+1][j+i] + dpf[j][j+k]*dpf[j+k+1][j+i];
                }
                
                k++;
            }
            dpt[j][j+i]=totalT;
            dpf[j][j+i]=totalF;
        }
    }
    return dpt[0][n-1];
}

int main() {
	//code
	
	string booleans;
	string operators;
	cin>>booleans>>operators;
	
	int count=booleanParenthesization(booleans,operators);
	cout<<count;
}