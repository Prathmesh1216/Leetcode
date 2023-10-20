class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    int solve(int node,vector<bool>& ha){
        vis[node] = 1;
        int ans = 0;
        bool flag = false;
        for(auto& it : g[node]){
            if(!vis[it]){
                int a = solve(it,ha);
                ans += a;
            } 
        }
        if(node!=0 && (ha[node] || ans>0)) ans += 2;
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ha) {
        g.resize(n);
        for(auto& it : edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vis.resize(n);
        return solve(0,ha);
    }
};