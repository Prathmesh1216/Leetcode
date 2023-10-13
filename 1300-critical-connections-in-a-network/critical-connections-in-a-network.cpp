class Solution {
public:
    vector<vector<int>> ans,g;
    vector<int> tin,vis,low;
    void dfs(int node,int par,int& timer){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto& it : g[node]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(it,node,timer);
                low[node] = min(low[it],low[node]);
                if(low[it]>tin[node]) ans.push_back({node,it});
            }
            else low[node] = min(low[node],tin[it]);
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.resize(n);
        for(auto& it : connections){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        int timer = 0;
        vis.resize(n);tin.resize(n);low.resize(n,123456789);
        for(int i = 0;i<n;i++){
            if(!vis[i]) dfs(i,-1,timer);
        }
        return ans;
    }
};