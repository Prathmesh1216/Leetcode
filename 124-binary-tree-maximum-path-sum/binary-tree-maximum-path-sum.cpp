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
    int ans = -123456789;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int lv = solve(root->left);
        int rv = solve(root->right);
        ans = max({ans,lv+root->val+rv,lv+root->val,root->val+rv,root->val});
        return max({root->val,root->val+lv,root->val + rv});
    }
    int maxPathSum(TreeNode* root) {
         solve(root);
         return ans;
    }
};