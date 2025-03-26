class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>a;
        int n=grid.size();
        int m=grid[0].size();
        //convert the grid into an array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a.push_back(grid[i][j]);
            }
        }
        //sort the array and find the median to get the target element
        sort(a.begin(),a.end());

        int l=a.size();
        //find the target element 
        int target=a[l/2];

        //check if (target-a)%x==0 true for all elements or not otherwise return 1(then its impossible to convert)
        for(int i=0;i<l;i++)
        {
            if((target-a[i])%x!=0)
            {
                return -1;
            }
        }
        //we know noOfOperations=|(target-a)|/x;
        int count=0;
        for(int i=0;i<l;i++)
        {
            count+=abs(target-a[i])/x;
        }
        return count;
    }
};