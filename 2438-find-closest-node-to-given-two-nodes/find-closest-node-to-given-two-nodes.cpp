class Solution {
public:
    vector<int> djikstra(int n,vector<int>& edges,int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> dist(n,123456789);
        dist[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            if(edges[node]!=-1){
                if(dist[edges[node]] > 1 + dist[node]){
                    dist[edges[node]] = 1 + dist[node];
                    pq.push({dist[edges[node]],edges[node]});
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> graph(n);
        vector<int> d1 = djikstra(n,edges,node1);
        vector<int> d2 = djikstra(n,edges,node2);
        int ans = 123456789;
        int na = -1;
        for(int i = 0;i<n;i++){
            if(ans> max(d1[i],d2[i])){
                ans = max(d1[i],d2[i]);
                na = i;
            }
        }
        return na;
        
    }
};