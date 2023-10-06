class Solution {
public:


    int bfs(int node,vector<int> adj[],int n){
       queue<pair<int,int>> q;
       vector<bool> vis(n,0);
       vector<int> dist(n,-1);
       dist[node] = 0;
       vis[node] = true;
       q.push({node,-1});
       int ans = INT_MAX;
       while(!q.empty()){
           int child = q.front().first;
           int par = q.front().second;
           q.pop();
           for(auto it : adj[child]){
               if(!vis[it]){
                   dist[it] = dist[child] + 1;
                   vis[it] = 1;
                   q.push({it,child});
               }
               else if(it!=par){
                   ans = min(ans,dist[it]+dist[child]+1);
               }
           }
       }
       return ans;

    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> count(n,1);
 
 
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int ans =  INT_MAX;
        for(int i = 0;i<n;i++){
            ans = min(ans,bfs(i,adj,n));
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};