class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis,tin,low;
    void dfs(int node,int parent,int& timer,vector<int> adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,timer,adj);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node]) ans.push_back({it,node});
            }
            else low[node] = min(low[node],tin[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(n,0);
        tin.resize(n,-1);
        low.resize(n,-1);
        int timer = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]) dfs(i,-1,timer,adj);
        }
        return ans;
    }
};