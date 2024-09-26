class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n=a.size();
    int k=a[0].size();
    int cnt=0;

    for(int i=0;i<k;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[j][i]<a[j-1][i])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
    }
};