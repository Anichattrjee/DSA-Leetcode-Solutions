class Solution {
public:
    int majorityElement(vector<int>& a) {
        //Applying Moore's Voting ALgorithm
        int n=a.size();
        int cnt=0;
        int el=0;

        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                el=a[i];
                cnt=1;
            }
            else if(el==a[i])
            {
                cnt++;
            }
            else cnt--;
        }

        int cnt1=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==el)cnt1++;
        }
        if(cnt1>n/2)
        {
            return el;
        }
        return -1;
    }
};