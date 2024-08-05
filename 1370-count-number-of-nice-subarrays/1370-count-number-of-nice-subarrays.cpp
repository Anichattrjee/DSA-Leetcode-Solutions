class Solution {
public:
    void transform_to_binary_array(vector<int>&a)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]%2==0)
            {
                a[i]=0;
            }
            else
            {
                a[i]=1;
            }
        }
    }

    int binary_subarray_sum(vector<int>&a, int goal)
    {
        int n=a.size();
        int l=0,r=0,sum=0,cnt=0;
        if(goal<0)return 0;

        while(r<n)
        {
            sum+=a[r];
            while(sum>goal)
            {
                sum=sum-a[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& a, int k) {
        transform_to_binary_array(a);
        int x=binary_subarray_sum(a,k);
        int y=binary_subarray_sum(a,k-1);
        return x-y;
    }
};