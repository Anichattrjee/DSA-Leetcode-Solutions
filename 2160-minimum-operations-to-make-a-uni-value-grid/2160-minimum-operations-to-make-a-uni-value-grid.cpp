class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>a;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a.push_back(grid[i][j]);
            }
        }
        sort(a.begin(),a.end());

        int l=a.size();
        int target=a[l/2];

        for(int i=0;i<l;i++)
        {
            if((target-a[i])%x!=0)
            {
                return -1;
            }
        }

        int count=0;
        for(int i=0;i<l;i++)
        {
            count+=abs(target-a[i])/x;
        }
        return count;
    }
};