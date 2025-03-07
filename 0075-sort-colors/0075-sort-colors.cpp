class Solution {
public:
    void sortColors(vector<int>& a) {
        //apply Dutch National Flag  Algorithm for optimal solution
        int n=a.size();
        int low=0;
        int mid=0;
        int high=n-1;
        //0...low-1 = only 0s
        //low..mid-1=only 1s
        //mid...high==unsorted
        //high+1 to n-1=onlly 2s
        while(mid<=high)
        {
            if(a[mid]==0)
            {
                swap(a[low],a[mid]);
                low++;
                mid++;
            }
            else if(a[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(a[mid],a[high]);
                high--;
            }
        }
    }
};