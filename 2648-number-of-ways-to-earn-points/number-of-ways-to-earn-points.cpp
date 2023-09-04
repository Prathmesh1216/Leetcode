class Solution {
public:
    int  n;
    int mod = 1e9+7;
    int dp[51][1001];
    int solve(int i,int target,vector<vector<int>>& types){
        if(target<0) return 0;
        if(target==0) return 1;
        if(i==n){
            if(target==0) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        long long ans = 0;
        for(int j = 0;j<=types[i][0];j++){
            ans += solve(i+1,target-j*types[i][1],types);
        }
        return dp[i][target] = ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,target,types);
    }
};