class Solution {
public:
    void com2_sum(int ind, int target, vector<int>&a, vector<vector<int>>&ans, vector<int>&ds)
    {
       if(target==0)
       {
           ans.push_back(ds);
       }
        //run the loop for each call from current index to last index
       for(int i=ind;i<a.size();i++)
       {
           
           //if the call with the same element has already done then no need to do (for selecting unique solution)
           
           if(i>ind && a[i]==a[i-1]) continue;
           
           //if a[i] is greater than target theen call is not possible
           if(a[i]>target)break;
           
           //add the element to the ds
           ds.push_back(a[i]);
           //call with next index as each element has to be taken once only
           com2_sum(i+1,target-a[i],a,ans,ds);
           //at the time of backtracking remove the element
           ds.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(),a.end());
	    vector<vector<int>>ans;
            vector<int>ds;
        com2_sum(0,target,a,ans,ds);
        return ans;
        
    }
};