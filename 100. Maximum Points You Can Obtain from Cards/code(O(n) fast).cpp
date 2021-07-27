class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int s=0,e=n-1;
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            sum = sum + cardPoints[e];
            e--;
        }
        e++;
        int maxPoints=sum;
        for(int i=1;i<=k;i++)
        {
            sum=sum-cardPoints[e++]+cardPoints[s++];
            maxPoints=max(maxPoints,sum);
        }
        return maxPoints;
    }
};