class Solution {
public:
    string leftJustify(vector<string>& words,int spaces,int i,int j,int n)
    {
        int gaps=j-i-1;  //Number of gaps between words in string if there exists 2 or more words
        //Note: gaps!=spaces 
        int spacesOnRight=spaces-gaps;
        string result=words[i];
        for(int k=i+1;k<j;k++)
        {
            result=result+" "+words[k];
        }
        result=result+ string(spacesOnRight,' ');
        return result;
    }
    
    // string(5,'k') --> yields string "kkkkk" 
    // string(number of repeatitions,char)
    
    string middleJustify(vector<string>& words,int spaces,int i,int j,int n)
    {
        int gaps=j-i-1;
        int spacesNeededBetween=spaces/gaps;
        int extraSpaces=spaces%gaps;
        string result=words[i];
        for(int k=i+1;k<j;k++)
        {
            int spacesToApply= spacesNeededBetween + (extraSpaces-- >0?1:0);
            result=result + string(spacesToApply,' ');
            result=result+words[k];
        }
        return result;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i=0;
        int n=words.size();
        while(i<n)
        {
            int j=i+1;
            int lineLen=words[i].length();
            while(j<n && lineLen+words[j].length()+j-i<=maxWidth)
            {
                lineLen=lineLen + words[j].length();
                j++;
            }
            int spaces=maxWidth - lineLen;
            int numOfWords=j-i;
            if(numOfWords==1 || j>=n)  result.push_back(leftJustify(words,spaces,i,j,n));
            else result.push_back(middleJustify(words,spaces,i,j,n));
            
            i=j;
        }
        return result;
    }
};
