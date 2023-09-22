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
    int ans = 0;
    void solve(TreeNode* root,long long sum){
        if(!root) return;
        if(root->val==sum) ans++;
        solve(root->left,sum-root->val);
        solve(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, int ts) {
        if(root){
            solve(root,ts);
            pathSum(root->left,ts);
            pathSum(root->right,ts);
        }
        return ans;
    }
};