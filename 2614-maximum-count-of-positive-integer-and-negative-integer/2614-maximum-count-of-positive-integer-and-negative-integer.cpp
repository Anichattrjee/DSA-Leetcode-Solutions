class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int poscount=0;
        int negcount=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                poscount++;
            }
            else if(nums[i]<0)
            {
                negcount++;
            }
            else 
            {
                continue;
            }
        }
        return max(poscount,negcount);
    }
};