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
    map<TreeNode*,int> sum,mp;
    int cnt(TreeNode* root){
        if(root==NULL) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        mp[root] = 1;
        return mp[root] += cnt(root->right) + cnt(root->left);
    }
    int tsum(TreeNode* root){
        if(root==NULL) return 0;
        if(sum.find(root)!=sum.end()) return sum[root];
        sum[root] = root->val;
        return sum[root] += tsum(root->left) + tsum(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        cnt(root);tsum(root);
        int ans = 0;
        for(auto& it : mp){
            if(it.first->val==0 && sum[it.first]==0) ans++;
            else if(it.second>0 && sum[it.first]/it.second == it.first->val) ans++;
        }
        return ans;
    }
};