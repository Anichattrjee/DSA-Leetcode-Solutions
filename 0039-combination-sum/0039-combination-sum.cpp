class Solution {
public:
    void com_sum(int i, vector<int>&a, vector<vector<int>>&v, vector<int>&ds,int target)
{
    //base case
	if(i==a.size())
    {
        if(target==0)
        {
            v.push_back(ds);
        }
        return;
    }
        
    //pick
    if(a[i]<=target)
    {
        ds.push_back(a[i]);
        com_sum(i,a,v,ds,target-a[i]);
        ds.pop_back();
    }
    com_sum(i+1,a,v,ds,target);
    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>v;
        vector<int>ds;
        com_sum(0,candidates,v,ds,target);
        return v;
    }
};