class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> g[n];
        for(auto &edge: flights)
        {
            g[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<vector<int>> q;
        q.push({0, src, 0});
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int stops = cur[0], node = cur[1], total = cur[2];
            if(stops>k) continue;
            for(auto &[child, cost]: g[node])
            {
                if(total + cost < dist[child])
                {
                    dist[child] = cost+total;
                    q.push({stops+1, child, cost+total});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};