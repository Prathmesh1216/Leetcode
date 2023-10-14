class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int i,int walls,vector<pair<int,int>>& v){
        if(walls>=n) return 0;
        if(i==n) return 1e9;
        if(dp[i][walls]!=-1) return dp[i][walls];
        int ans = v[i].first + solve(i+1,walls + v[i].second + 1,v);
        ans = min(ans,solve(i+1,walls,v));
        return dp[i][walls] = ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        vector<pair<int,int>> v;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<n;i++) v.push_back(make_pair(cost[i],time[i]));
        return solve(0,0,v);
    }
};