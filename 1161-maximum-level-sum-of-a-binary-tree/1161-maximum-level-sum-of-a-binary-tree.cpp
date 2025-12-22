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
    void bfs(TreeNode * root, int &maxsum, int &resultlevel,int currlevel, queue<TreeNode *>q)
    {
        if(root==NULL)return;
        q.push(root);
        currlevel=1;
        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
        
            while(size--)
            {
                TreeNode * node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }

            }
            if(sum>maxsum)
            {
                maxsum=sum;
                resultlevel=currlevel;
            }
            currlevel++;
        }
    }
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int resultlevel=0;
        queue<TreeNode *>q;
        bfs(root,maxSum,resultlevel,1,q);
        return resultlevel;
    }
};