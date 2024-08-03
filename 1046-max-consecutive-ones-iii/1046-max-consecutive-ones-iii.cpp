class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n=a.size();
        int zeroes=0,l=0,r=0,maxlen=0;

        while(r<n)
        {
            if(a[r]==0)zeroes++;
            if(zeroes>k)
            {
                if(a[l]==0)zeroes--;
                l++;
            }
            if(zeroes<=k)
            {
                maxlen=max(maxlen,r-l+1);
            }
            r++;    
        }
        return maxlen;
    }
};