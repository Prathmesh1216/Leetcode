class Solution {
public:
    bool dfs(int node,int par,vector<bool>& vis,vector<int>& color,vector<vector<int>>& graph){
        vis[node] = 1;
        bool flag = true;
        for(auto& it : graph[node]){
            if(!vis[it]){
                color[it] = 1-color[node];
                flag &= dfs(it,node,vis,color,graph);
            }
            else if(it!=par && color[it]==color[node]) return false;
        }
        return flag;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        vector<bool> vis(n);
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(!vis[i]) color[i] = 0,flag&= dfs(i,-1,vis,color,graph); 
        }
        return flag;
    }
};