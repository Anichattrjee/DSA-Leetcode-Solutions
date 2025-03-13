class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[nums[i]]==1)
            {
                ans=nums[i];
                return ans;
            }
            else
            {
                visited[nums[i]]=1;
            }
        }
        return ans;
    }
};