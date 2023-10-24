class Solution {
public:
#define pb push_back
    int reachableNodes(vector<vector<int>>& edges, int mm, int n) {
        vector<vector<pair<int,int>>> g(n);
        int a = n;
        for(auto& it : edges){
            g[it[0]].pb({it[1],it[2]+1});
            g[it[1]].pb({it[0],it[2]+1});
        }
        queue<int> q;
        q.push(0);
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto& [it,dis] : g[node]){
                if(dist[it]>dis + dist[node]){
                    dist[it] = dis + dist[node];
                    q.push(it);
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(dist[i]<=mm) cnt++;
        }
        for(auto& it : edges){
            int a = max(0,mm-dist[it[0]]);
            int b = max(0,mm-dist[it[1]]);
            cnt += min(a+b,it[2]);
        }
        return cnt;
    }
};