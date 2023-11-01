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
    unordered_map<int,int> mp;
    void solve(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        solve(root);
        int mini = 0;
        for(auto& it : mp){
            mini = max(mini,it.second);
        }
        if(!mini) return {};
        for(auto& it : mp) if(it.second==mini) ans.push_back(it.first);
        return ans;

    }
};