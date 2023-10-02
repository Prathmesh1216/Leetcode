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
    int m = 1e9+7;
    map<TreeNode*,long long> dp;
    long long solve(TreeNode* root){
        if(dp.find(root)!=dp.end()) return dp[root];
        long long ans = root->val;
        if(root->left) ans +=solve(root->left);
        if(root->right) ans += solve(root->right);
        return dp[root] = ans;
    }
    int maxProduct(TreeNode* root) {
        solve(root);
        queue<TreeNode*> q;
        long long ans = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) ans = max(ans,dp[node->left]*(dp[root]-dp[node->left]));
            if(node->right) ans = max(ans,dp[node->right]*(dp[root]-dp[node->right]));
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right); 
        }
        return ans%m;
    }
};