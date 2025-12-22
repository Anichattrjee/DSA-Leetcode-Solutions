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
    //approach -1
    // void solve(TreeNode * root, int steps, int &maxPath, bool goLeft)
    // {
    //     if(root==NULL)return;
    //     //update maxpath always
    //     maxPath=max(maxPath,steps);

    //     //if goLeft is true then go left and if is false then go right
    //     if(goLeft)
    //     {
    //         solve(root->left, steps+1,maxPath,false);
    //         solve(root->right,1,maxPath,true);
    //     }
    //     else
    //     {
    //         solve(root->right,steps+1,maxPath,true);
    //         solve(root->left,1,maxPath,false);
    //     }
    // }
        
    //approach-2
    void solve(TreeNode * root,int l, int r, int &maxPath)
    {
        if(root==NULL)return;

        maxPath=max(maxPath,max(l,r));
        solve(root->left,r+1,0,maxPath);
        solve(root->right,0,l+1,maxPath);
    }

    int longestZigZag(TreeNode* root) {
        //approach-1
        // int maxPath=0;
        // bool goLeft=true;
        // int steps=0;
        // solve(root,steps,maxPath,goLeft);
        // return maxPath;

        //approach-2
        int maxPath=0;
        solve(root,0,0,maxPath);
        return maxPath;
    }
};