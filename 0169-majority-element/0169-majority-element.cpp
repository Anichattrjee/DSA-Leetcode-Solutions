class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ele=0;
        //applying boyre moore's voting algorithm
        for(int x:nums)
        {
            //if count==0 then set element = current element and increase count to 1
            if(cnt==0)
            {
                cnt=1;
                ele=x;
            }
            //if current element = element then increase count
            else if(x==ele)cnt++;
            //otherwise decrease count
            else cnt--;
        }

        //if there's any majority element it will be in the element
        int occ=0;
        for(int x:nums)
        {
            if(x==ele)occ++;
        }
        //if occurance is greater than n/2 then return the element
        if(occ>n/2)return ele;
        return -1;
    }
};