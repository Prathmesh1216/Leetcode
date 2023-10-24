class Solution {
public:
    int n;
    int m = 1e9+7;
    int dp[31][1001];
    int solve(int i,int k,int target){
        if(i==n) return target==0;
        if(dp[i][target]!=-1) return dp[i][target];
        long long ans = 0;
        for(int j = 1;j<=k;j++){
            if(target-j>=0) ans += solve(i+1,k,target-j)%m;
        }
        return dp[i][target] = ans%m;
    }
    int numRollsToTarget(int N, int k, int target) {
        n = N;
        memset(dp,-1,sizeof(dp));
        return solve(0,k,target);
    }
};