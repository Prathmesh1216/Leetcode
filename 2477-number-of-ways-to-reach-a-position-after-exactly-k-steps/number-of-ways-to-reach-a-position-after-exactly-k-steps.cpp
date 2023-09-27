class Solution {
public:
   int mod = 1e9+7;
   long long dp[4001][1001];
    long long solve(int i,int target,int k){
        if(target-i>k) return 0;
        if(k==0){
            if(i==target) return 1;
            return 0;
        }
        if(dp[i+2000][k]!=-1) return dp[i+2000][k];
        return dp[i+2000][k] = solve(i-1,target,k-1)%mod + solve(i+1,target,k-1)%mod;
    }
    int numberOfWays(int sp, int ep, int k) {
        if(ep<sp) swap(sp,ep);
        memset(dp,-1,sizeof(dp));
        return solve(0,ep-sp,k)%mod;
    }
};