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
    int maxPathSum(TreeNode* root) {
        int maxpath = INT_MIN;
        sum(root,maxpath);
        return maxpath ;
    }
    int sum(TreeNode* root,int &maxi)
    {
        if(root ==NULL)return 0;
        int lsum = sum(root->left,maxi);
        int rsum = sum(root->right,maxi);
        maxi = max(maxi,root->val + lsum + rsum);
        if((root->val + max(lsum,rsum))> 0 ) return root->val + max(lsum,rsum);
        else return 0;
    }
};