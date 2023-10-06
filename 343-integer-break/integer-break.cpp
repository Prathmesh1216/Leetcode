class Solution {
public:
    int dp[59];
    int solve(int n){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans = n;
        for(int i = 1;i<=n/2;i++){
            ans = max(ans,i*solve(n-i));
        }
        return dp[n] =  ans;
    }
    int integerBreak(int n) {
        if(n<4) return n-1;
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};