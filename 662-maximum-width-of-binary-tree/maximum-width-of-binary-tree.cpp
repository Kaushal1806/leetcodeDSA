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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        int width = 0;
        while(!q.empty())
        {
            int mini = q.front().second;
            int size = q.size();
            int left;
            int right;

            for(int i = 0;i<size;i++)
            {
                if (i == 0) left = q.front().second - mini;
                if (i == size-1) right = q.front().second - mini;
                if(q.front().first->left)
                {
                    q.push({  q.front().first->left  ,(long long) 2*(q.front().second - mini)+1 });
                }
                if(q.front().first->right)
                {
                    q.push({  q.front().first->right  ,(long long) 2*(q.front().second - mini)+2 });
                }
                q.pop();
            }
            width = max(width,right-left+1);
        }
        return width;
    }
};