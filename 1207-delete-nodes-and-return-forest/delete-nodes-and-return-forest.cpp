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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        queue<pair<TreeNode*,TreeNode*>> q;
        vector<bool> todelete(1001);
        for(int i = 0;i<to_delete.size();i++) todelete[to_delete[i]] = 1;
        if(!todelete[root->val]) ans.push_back(root);
        q.push({root,NULL});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            TreeNode* parent = q.front().second;
            q.pop();
            if(todelete[node->val]){
                if(node->left && !todelete[node->left->val]) ans.push_back(node->left);
                if(node->right && !todelete[node->right->val]) ans.push_back(node->right);
                if(parent!=NULL){
                    if(parent->right && parent->right->val==node->val) parent->right = NULL;
                    else if(parent->left && parent->left->val==node->val) parent->left = NULL;
                }
            }
            if(node->right) q.push({node->right,node});
            if(node->left) q.push({node->left,node});
            node = NULL;
        }
        return ans;

    }
};