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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)return ans;

        queue<TreeNode*>q;
        q.push(root);
        
        bool ltor = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int>row;

            for(int i = 0;i<size;i++)
            {
                row.push_back(q.front()->val);

                if(q.front()->left != NULL)q.push(q.front()->left);
                if(q.front()->right != NULL)q.push(q.front()->right);

                q.pop();
            }
            if(ltor)
            {
                ans.push_back(row);
                ltor = false;
            }
            else
            {
                reverse(row.begin(),row.end());
                ans.push_back(row);
                ltor = true;
            }
        }
        return ans;

    }
};