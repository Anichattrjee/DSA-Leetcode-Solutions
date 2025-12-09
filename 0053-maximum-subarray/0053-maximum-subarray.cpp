class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxSum=INT_MIN;//to cover the negative sums also

        for(int x:nums)
        {
            //add the no to the sum
            // if sum<0 then reintialize the sum to 0
            sum=max(x, sum+x);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
        
    }
};