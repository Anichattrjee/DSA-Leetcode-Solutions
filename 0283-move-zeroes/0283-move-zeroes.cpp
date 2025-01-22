class Solution {
public:
    void moveZeroes(vector<int>& a) {
       int n=a.size();

       //find out the first zero index
       int j=-1;
       for(int i=0;i<n;i++)
       {
        if(a[i]==0)
        {
            j=i;
            break;
        }
       }

       //if theres no zero in the array just return
       if(j==-1)return;

       //point i next to j
       for(int i=j+1;i<n;i++)
       {
        //if a[i] is a zero then just increase i
        if(a[i]==0)
        {
            continue;
        }
        //else swap a[i] with a[j] and then increase both i and j
        else{
            swap(a[i],a[j]);
            j++;
        }
       }
    }
};