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
    int height(TreeNode* root){
        if(root==NULL) return -1;
        return max(1+height(root->left),1+height(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
       int h = height(root); 
       queue<TreeNode*> q;
       int level = 0;
       q.push(root);
       long long ans = 0;
       while(!q.empty()){
           int n = q.size();
           while(n--){
               TreeNode* root = q.front();
               q.pop();
               if(level==h) ans += root->val;
               if(root->right) q.push(root->right);
               if(root->left) q.push(root->left);
           }
           level++;
       }
       return ans;
    }
};