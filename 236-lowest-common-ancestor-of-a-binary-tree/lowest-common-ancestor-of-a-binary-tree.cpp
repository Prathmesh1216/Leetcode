/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,TreeNode*> mp;
    vector<vector<int>> path(TreeNode* root,TreeNode* p,TreeNode* q){
        queue<pair<TreeNode*,vector<int>>> qu;
        vector<int> temp; temp.push_back(root->val);
        mp[root->val] = root;
        qu.push({root,temp});
        vector<vector<int>> ans(2);
        while(!qu.empty()){
            TreeNode* t = qu.front().first; vector<int> t1 = qu.front().second;qu.pop();
            if(t->val==p->val){
                ans[0] = t1;
            }
            if(t->val==q->val){
                ans[1] = t1;
            }
            if(t->left){
                mp[t->left->val] = t->left;
                t1.push_back(t->left->val);
                qu.push({t->left,t1});
                t1.pop_back();
            }
            if(t->right){
                mp[t->right->val] = t->right;
                t1.push_back(t->right->val);
                qu.push({t->right,t1});
            }
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<vector<int>> v = path(root,p,q);
        int i = 0;
        int a = v[0].size();
        a = min(a,(int)v[1].size());
        while(i<a && v[0][i]==v[1][i]){
            i++;
        }  
        i--;
        return mp[v[0][i]];
    }
};