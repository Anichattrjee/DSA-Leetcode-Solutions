/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         //if root is null or any of the given nodes return root
        if(root==NULL || root==p || root==q)return root;

        //now call for left and right
        //if left null return right if right null return left
        TreeNode *  left=lowestCommonAncestor(root->left,p,q);
        TreeNode * right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        else if(right==NULL)return left;
        else return root;
    }
};