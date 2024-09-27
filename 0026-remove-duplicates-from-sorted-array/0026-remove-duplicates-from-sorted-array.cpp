class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(a[i]!=a[j])
            {
                i++;
                a[i]=a[j];
            }
        }
        return i+1;
    }
};