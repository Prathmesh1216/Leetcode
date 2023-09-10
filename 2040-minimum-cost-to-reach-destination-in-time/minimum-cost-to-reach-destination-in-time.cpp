class Solution {
public:
    int n;
    long long dp[1001][1001];
    long long dfs(int node,int time,int mt,vector<pair<int,int>> adj[],vector<int>& pf){
        if(time>mt) return 123456789;
        if(node==n-1) return pf[n-1];
        if(dp[node][time]!=-1) return dp[node][time];
        long long ans = 123456789;
        for(auto it : adj[node]){
            ans = min(ans,dfs(it.first,time+it.second,mt,adj,pf));
        }
        return dp[node][time] = ans+pf[node];
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        n = passingFees.size();
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> adj[n];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int dis = it[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        long long ans = dfs(0,0,maxTime,adj,passingFees);
        return (ans>=123456789)?-1:ans;
    }
};