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
    int solve(TreeNode *  root, int curr)
    {
        if(!root)return 0;
        curr=(curr*10)+root->val;//create the no
        //if leaf node then return the no
        if(root->left==NULL && root->right==NULL)return curr;

        //if not leaf then call for left subtree and right subtree
        int left=solve(root->left,curr);
        int right=solve(root->right,curr);
        //if at root return left+right which is the sum
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        int curr=0;
        int ans=solve(root,curr);
        return ans;
    }
};