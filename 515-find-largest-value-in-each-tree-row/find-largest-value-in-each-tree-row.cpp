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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        int level = 0;
        int cl = 0;
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int maxi = INT_MIN;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                maxi = max(maxi,node->val);
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};