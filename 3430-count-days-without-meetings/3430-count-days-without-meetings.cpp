class Solution {
public:
    int countDays(int days, vector<vector<int>>& a) {
       int daysoff=0;
       int n=a.size();
       sort(a.begin(),a.end());

       int start=0;
       int end=0;
       for(int i=0;i<n;i++)
       {
        if(a[i][0]>end)
        {
            daysoff+=a[i][0]-end-1;
        }
        end=max(end,a[i][1]);
       }
       if(days>end)
       {
        daysoff+=days-end;
       }
       return daysoff;
    }
};