class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int i,int walls,vector<int>& cost,vector<int>& time){
        if(walls>=n) return 0;
        if(i==n) return 1e9;
        if(dp[i][walls]!=-1) return dp[i][walls];
        int ans = cost[i] + solve(i+1,walls + time[i] + 1,cost,time);
        ans = min(ans,solve(i+1,walls,cost,time));
        return dp[i][walls] = ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,cost,time);
    }
};