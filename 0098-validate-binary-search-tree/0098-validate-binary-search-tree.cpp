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
    bool isValidBSTree(TreeNode * root, long long minval, long long maxval)
    {
        if(root==NULL)return true;
        if(root->val >=maxval || root->val<=minval)return false;//out of the range
        return isValidBSTree(root->left,minval, root->val) && isValidBSTree(root->right, root->val,maxval);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTree(root,  numeric_limits<long long>::min(),
                              numeric_limits<long long>::max());
    }
};