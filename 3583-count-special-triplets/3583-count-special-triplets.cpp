class Solution {
public:
    int M=1e9+7;

    int specialTriplets(vector<int>& nums) {
        //better approach using two maps
        map<int,int>mp_left;
        map<int,int>mp_right;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp_right[nums[i]]++;
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            mp_right[x]--;
            
            int left=mp_left[x*2];
            int right=mp_right[x*2];

            cnt = (cnt + (1LL *left *right)) % M;
            
            mp_left[x]++;
            
        }
        return cnt;
    }
};