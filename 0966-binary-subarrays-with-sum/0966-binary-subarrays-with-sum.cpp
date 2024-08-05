class Solution {
public:
    int binarySum(vector<int>&a,int goal)
    {
        int n=a.size();
        int l=0,r=0,sum=0,cnt=0;
        if(goal<0)return 0;

        while(r<n)
        {
            sum+=a[r];
            while(sum>goal)
            {
                sum=sum-a[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>&a, int goal) {
        int x=binarySum(a,goal);
        int y=binarySum(a,goal-1);
        return x-y;
    }
};