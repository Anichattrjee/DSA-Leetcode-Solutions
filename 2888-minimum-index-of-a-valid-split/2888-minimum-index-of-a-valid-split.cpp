class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;

        int n1=0;
        int n2=0;

        for(int i=0;i<n;i++)
        {
            m2[nums[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            int el=nums[i];
            m1[el]++;
            m2[el]--;
            n1=i+1;
            n2=n-i-1;

            if(m1[el]>n1/2 && m2[el]>n2/2)
            {
                return i;
            }
        }
        return -1;
    }
};