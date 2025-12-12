/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode * root, vector<int>&temp, int level)
    {
        if(root==NULL)return;
        if(level==temp.size())temp.push_back(root->val);
        solve(root->right,temp,level+1);
        solve(root->left,temp,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>temp;
        int level=0;
        solve(root,temp,level);
        return temp;
    }
};