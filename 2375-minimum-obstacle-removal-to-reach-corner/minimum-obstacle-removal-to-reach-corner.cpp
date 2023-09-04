
class Solution {
public:
    int n,m;
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};
        vector<pair<int,int>> adj[n*m];
        vector<vector<int>> names(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                names[i][j] = cnt;
                cnt++;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<4;k++){
                    int ni = i + dr[k];
                    int nj = j + dc[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        adj[names[i][j]].push_back({names[ni][nj],grid[ni][nj]});
                    }
                }
            }
        }
        vector<int> dist(n*m,INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int nnode = it.first;
                if(dist[node]+it.second<dist[nnode]){
                    dist[nnode] = dist[node]+it.second;
                    pq.push({dist[nnode],nnode});
                }
            }
        }
        return dist[n*m-1];
    }

};