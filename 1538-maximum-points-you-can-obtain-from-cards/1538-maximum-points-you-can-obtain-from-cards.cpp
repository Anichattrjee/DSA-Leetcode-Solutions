class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int sum=0;
        int maxsum=0;
        int leftSum=0,rightSum=0;
        int l=0,r=n-1;

        for(int l=0;l<k;l++)
        {
            leftSum+=a[l];
            maxsum=leftSum+rightSum;
        }

        

        for(int i=k-1;i>=0;i--)
        {
            leftSum-=a[i];
            rightSum+=a[r];
            r--;
            sum=leftSum+rightSum;
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};