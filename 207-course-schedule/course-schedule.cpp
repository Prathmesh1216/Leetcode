class Solution {
public:
    vector<vector<int>> adj;
    bool dfs(int node,vector<bool>& vis,vector<bool>& dfsvis){
        vis[node] = 1;
        dfsvis[node] = 1;
        bool flag = false;
        for(auto& it : adj[node]){
            if(!vis[it]) flag|=dfs(it,vis,dfsvis);
            else if(dfsvis[it]){
                flag = true;
            }
        }
        dfsvis[node] = 0;
        return flag;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        adj.resize(n);
        for(auto& it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        bool flag = false;
        vector<bool> vis(n),dfsvis(n);
        for(int i = 0;i<n;i++){
            if(!vis[i]) flag |= dfs(i,vis,dfsvis);
        }
        return !flag;
    }
};