class Solution {
public:
    int n;
    int bfs(int src,vector<vector<pair<int,int>>>& g){
        queue<int> q;
        int cnt = 0;
        vector<bool> vis(n);
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto& it : g[node]){
                if(!vis[it.first]){
                    vis[it.first] = 1;
                    q.push(it.first);
                    if(it.second==-1) cnt++;
                }
            }
        }
        return cnt;
    }
    vector<int> minEdgeReversals(int N, vector<vector<int>>& edges) {
        n = N;
        vector<vector<pair<int,int>>> g(n);
        for(auto& it : edges){
            g[it[1]].push_back({it[0],-1});
            g[it[0]].push_back({it[1],1});
        }
        vector<int> count(n);
        count[0] = bfs(0,g);
        queue<int> q;
        vector<bool> vis(n);
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& it : g[node]){
                if(!vis[it.first]){
                    vis[it.first] = 1;
                    q.push(it.first);
                    count[it.first] = count[node] + it.second;
                }
            }
        }
        return count;
    }
};