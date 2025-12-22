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
    void dfs(TreeNode * root, int depth, vector<int>&result)
    {
        if(root==NULL)return;
        if(depth==result.size())
        {
            result.push_back(root->val);
        }
        else
        {
            result[depth]=max(result[depth],root->val);
        }
        if(root->left)dfs(root->left,depth+1,result);
        if(root->right)dfs(root->right,depth+1,result);
    }
    vector<int> largestValues(TreeNode* root) {
        //approach-1 -- bfs
        // vector<int>temp;
        // if(root==NULL)return temp;
        // queue<TreeNode *>q;
        // q.push(root);
        // while(!q.empty())
        // {
        //     int n=q.size();
        //     int maxelement=INT_MIN;
        //     while(n--)
        //     {
        //         TreeNode * node=q.front();
        //         q.pop();
        //         maxelement=max(maxelement,node->val);
        //         if(node->left)
        //         {
        //             q.push(node->left);
        //         }
        //         if(node->right)
        //         {
        //             q.push(node->right);
        //         }
        //     }
        //     temp.push_back(maxelement);
        // }
        // return temp;

        //approach-2 --dfs
        vector<int>result;
        if(!root)return result;

        dfs(root,0,result);
        return result;
    }
};