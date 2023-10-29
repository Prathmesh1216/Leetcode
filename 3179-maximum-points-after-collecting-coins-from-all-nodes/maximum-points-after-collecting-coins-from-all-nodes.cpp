class Solution {
public:
    int cv(int n,int times){
        while(times--){
            n = floor(n/2);
        }
        return n;
    }
   vector<vector<int>> dp;
    int solve(int node,int times,int par,vector<vector<int>>& g,vector<int>& coins,int k){
        int nv = cv(coins[node],times);
        if(dp[node][times]!=INT_MIN) return dp[node][times];
        if(times>=14) return dp[node][times] = 0;
        int ans1 = nv - k;
        for(auto& it : g[node]) if(it!=par) ans1 += solve(it,times,node,g,coins,k);
        int ans2 = floor(nv/2);
        for(auto& it : g[node]) if(it!=par) ans2 += solve(it,times+1,node,g,coins,k);
        return dp[node][times] = max(ans1,ans2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(15,INT_MIN));
        vector<vector<int>> g(n);
        for(auto& it : edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        return solve(0,0,-1,g,coins,k);
    }
};