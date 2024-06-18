class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        vector<int>maxL;
        vector<int>maxR;

        maxL.push_back(a[0]);
        maxR.push_back(a[n-1]);

        //finding the maximum element in the left array
        for(int i=1;i<n;i++)
        {
            maxL.push_back(max(maxL[i-1],a[i]));
        }

        //finding the maximum element in the right array
        for(int i=n-2;i>=0;i--)
        {
            maxR.push_back(max(maxR.back(),a[i]));
        }

        reverse(maxR.begin(),maxR.end());





        vector<int>w;
        for(int i=0;i<n;i++)
        {
            w.push_back(min(maxL[i],maxR[i])-a[i]);
        }



        int total_water=0;
        for(int i=0;i<n;i++)
        {
            total_water+=w[i];
        }

        return total_water;


    }
};