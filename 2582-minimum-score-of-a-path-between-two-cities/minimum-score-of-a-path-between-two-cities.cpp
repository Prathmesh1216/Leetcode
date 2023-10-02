class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
   vector<pair<int,int>> adj[n+1];
   for(int i=0;i<roads.size();i++){
       adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
       adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
   }
        vector<int> dist(n+1,INT_MAX);
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[it.first]>min(dist[node],it.second)){
                    dist[it.first]=min(dist[node],it.second);
                    q.push(it.first);
                }
            }
        }
        return dist[n];
    }
};