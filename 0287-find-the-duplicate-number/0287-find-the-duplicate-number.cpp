class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<int>hash(n,0);

        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(hash[i]>1)
            {
                ans=i;
                return ans;
            }
        }
        return ans;
    }
};