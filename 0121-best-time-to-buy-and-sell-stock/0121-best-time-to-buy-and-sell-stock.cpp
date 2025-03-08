class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int maxProfit=0;
        int mini=a[0];

        for(int i=1;i<n;i++)
        {
            int cost=a[i]-mini;
            maxProfit=max(maxProfit,cost);
            mini=min(mini,a[i]);
        }

        return maxProfit;
    }
};