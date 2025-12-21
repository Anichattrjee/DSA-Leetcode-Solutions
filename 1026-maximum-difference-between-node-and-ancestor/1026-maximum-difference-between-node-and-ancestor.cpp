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
    int findMaxDiff(TreeNode * root,int minV, int maxV)
    {
        if(root==NULL){
            return abs(maxV-minV);
        }

        minV=min(minV,root->val);
        maxV=max(maxV,root->val);

        int leftDiff=findMaxDiff(root->left,minV,maxV);
        int rightDiff=findMaxDiff(root->right,minV,maxV);

        return max(leftDiff,rightDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int minV=INT_MAX;
        int maxV=INT_MIN;

        int maxDiff=findMaxDiff(root,minV,maxV);

        return maxDiff;


    }
};