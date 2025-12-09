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
    TreeNode * buildUniqueTree(vector<int>& preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, map<int,int>&mp)
    {
        if(preStart>preEnd || inStart >inEnd)return NULL;//arrays ended

        TreeNode * root=new TreeNode(preorder[preStart]);

        //find the index of root in order
        int inRoot=mp[root->val];
        //find how many nos to the left (X)
        int numsLeft=inRoot-inStart;

        root->left=buildUniqueTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
        root->right=buildUniqueTree(preorder,preStart+numsLeft+1, preEnd, inorder, inRoot+1,inEnd,mp);

        return root;
    }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        //hasing all elements of inorder to get their indexes fast
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }

        TreeNode * root=buildUniqueTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);

        return root;
    }

    
};