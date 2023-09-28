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

    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,-1));
        int level = 0;
        int xparent = -1,yparent = -1,xlevel = -1,ylevel = -1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front().first;
                int par = q.front().second;
                q.pop();
                if(temp->val==x){
                    xparent = par;
                    xlevel = level;
                }
                if(temp->val==y){
                    yparent = par;
                    ylevel = level;
                }
                if(temp->left!=NULL){
                    q.push(make_pair(temp->left,temp->val));
                }
                if(temp->right!=NULL){
                    q.push(make_pair(temp->right,temp->val));

                }

            }
            level++;
        }
        if(xlevel==ylevel && xparent!=yparent) return true;
        return false;

    }
};