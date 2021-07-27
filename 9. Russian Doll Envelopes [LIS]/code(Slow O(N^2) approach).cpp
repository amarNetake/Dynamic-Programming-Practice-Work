int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n=envelopes.size();  //Total number of envelopes
        
        //Sort the envelopes in decreasing order. It will be sorted by first column. If data at first column matches then by 2nd column
        sort(envelopes.begin(),envelopes.end());
        reverse(envelopes.begin(),envelopes.end());
        
        vector<int> lds(n,1);  //Longest decreasing subsequence that ends at index i
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1] && lds[i] < lds[j] + 1)
                {
                    lds[i]=lds[j]+1;
                }
            }
        }
        int maxCount=0;
        for(int i=0;i<n;i++)
        {
            maxCount=max(maxCount,lds[i]);
        }
        return maxCount;
    }