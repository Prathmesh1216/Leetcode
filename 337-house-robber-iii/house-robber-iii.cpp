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
    map<pair<TreeNode*,int>,int> dp;
    int solve(TreeNode* root,bool canrob){
        if(root==NULL) return 0;
        if(dp.find({root,canrob})!=dp.end()) return dp[{root,canrob}];
        if(!canrob){
            return dp[{root,canrob}] = solve(root->left,1) + solve(root->right,1);
        }
        return dp[{root,canrob}] = max(root->val + solve(root->left,0) + solve(root->right,0),solve(root->left,1) + solve(root->right,1));
    }
    int rob(TreeNode* root) {
        return solve(root,1);
    }
};