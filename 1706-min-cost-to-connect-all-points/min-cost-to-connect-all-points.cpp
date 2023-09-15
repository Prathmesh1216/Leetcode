class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
             int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
             adj[i].push_back({j,dist});
             adj[j].push_back({i,dist});
            }
        }
        int cost = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(n,0);
        while(!pq.empty()){
            int prev = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(vis[prev]) continue;
            cost += wt;
            vis[prev] = 1;
            for(auto it : adj[prev]){
                int node = it.first;
                int w = it.second;
                if(!vis[node]) pq.push({w,node});
            }
        }
        return cost;

        
    }
};