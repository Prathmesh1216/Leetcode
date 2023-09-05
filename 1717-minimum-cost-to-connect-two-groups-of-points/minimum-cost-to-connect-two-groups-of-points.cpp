class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int get(int j,vector<vector<int>>& cost){
        int mini = cost[0][j];
        for(int i = 1;i<n;i++){
            mini = min(mini,cost[i][j]);
        }
        return mini;
    }
    int solve(int i,int mask,vector<vector<int>>& cost){
        if(i==n){
            int ans = 0;
            for(int j = 0;j<m;j++){
                if(!(mask&(1<<j))) ans += get(j,cost);
            }
            return ans;
        }
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans = 123456789;
        for(int j = 0;j<m;j++){
            ans = min(cost[i][j]+solve(i+1,mask|(1<<j),cost),ans);
        }
        return dp[i][mask]  = ans;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        n = cost.size();
        m = cost[0].size();
        dp.resize(n+1,vector<int>(1<<m,-1));
        return solve(0,0,cost);
    }
};