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
    TreeNode* replaceValueInTree(TreeNode* Root) {
        TreeNode* root = Root;
        map<int,int> levelsum;
        map<TreeNode*,TreeNode*> parent;
        map<TreeNode*,int> nodelevel;
        int level = 0;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front().first;
                parent[temp] = q.front().second;
                q.pop();
                levelsum[level] += temp->val;
                nodelevel[temp] = level;
                if(temp->left){
                    q.push(make_pair(temp->left,temp));
                }
                if(temp->right){
                    q.push(make_pair(temp->right,temp));
                }
                
            }
            level++;
        }
    //    cout << parent[root->left]->val << endl;
        set<TreeNode*> vis;
        for(auto& it : parent){
            if(vis.find(it.first)!=vis.end()) continue;
            if(it.second==NULL) {it.first->val = 0;continue;}
            int l = nodelevel[it.first];
            int a = levelsum[l];
            if(it.second->left) a -= it.second->left->val;
            if(it.second->right) a-= it.second->right->val;
            if(it.second->left) it.second->left->val = a,vis.insert(it.second->left);
            if(it.second->right) it.second->right->val = a,vis.insert(it.second->right);
        }
        return Root;
    }
};
        // for(auto& it : nodelevel){
        //     cout << it.first->val << "->" << it.second << endl;
        // }
        // for(auto& it : parent){
        //     if(it.second==NULL) {cout << it.first << endl;continue;}
        //     cout << it.first->val << "->" << it.second->val << endl;
        // }
        // for(auto& it : levelsum){
        //     cout << it.first << "->" << it.second << endl;
        // }