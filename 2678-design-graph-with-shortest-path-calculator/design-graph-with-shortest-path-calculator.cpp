class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int n;
    Graph(int N, vector<vector<int>>& edges) {
        adj.resize(N);
        n = N;
        for(auto& it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n,123456789);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        dist[node1] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            for(auto& it : adj[node]){
                if(dist[it.first]>it.second+dist[node]){
                    dist[it.first] = it.second+dist[node];
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return (dist[node2]>=123456789)?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */