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
    TreeNode * addRow(TreeNode * root, int val, int depth,  int curr)
    {
        if(root==NULL)return NULL;
        if(curr==depth-1)
        {
            //store the old left child and right child first
            TreeNode * oldLeft=root->left;
            TreeNode * oldRight=root->right;

            //create the new nodes and add them to root->left and right
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);

            //add the old left and right child to the left and right of the new nodes
            root->left->left=oldLeft;
            root->right->right=oldRight;

            return root;
        }
        //otherwise call for  the lef subtree and right subtree with curr+1
        root->left=addRow(root->left, val, depth, curr+1);
        root->right=addRow(root->right, val, depth, curr+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)return NULL;
        if(depth==1)
        {
            TreeNode * newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        int curr=1;
        return addRow(root, val, depth, curr);
    }
};