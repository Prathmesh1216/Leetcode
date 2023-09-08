class Solution {
public:
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<int> adj[n];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto cmp = [&scores] (const int u,int v) {return scores[u]>scores[v];};
        for(int i = 0;i<n;i++){
            sort(adj[i].begin(),adj[i].end(),cmp);
        }
        int ans = -1;
        for(int k = 0;k<edges.size();k++){
            int u = edges[k][0];
            int v = edges[k][1];
            int least = scores[u] + scores[v];
            int s = adj[u].size();
            for(int i = 0;i<min(3,s);i++){
                if(adj[u][i]==v) continue;
                int t = adj[v].size();
                for(int j = 0;j<min(3,t);j++){
                    if(adj[v][j]==u || adj[v][j]==adj[u][i]) continue;
                    ans = max(ans,least+scores[adj[v][j]]+scores[adj[u][i]]);
                }
            }
        }
        return ans;
    }
        
};