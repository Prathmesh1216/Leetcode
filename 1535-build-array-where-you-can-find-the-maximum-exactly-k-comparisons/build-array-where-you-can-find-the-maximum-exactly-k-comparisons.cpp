class Solution {
public:
    int dp[51][51][101];
    const int mod = 1e9+7;
    int solve(int len,int k,int lm,int m){
        if(k<0) return 0;
        if(len==0){
            if(k==0) return 1;
            return 0;
        }
        if(dp[len][k][lm]!=-1) return dp[len][k][lm];
        long long ans = 0;
        for(int i = 1;i<=m;i++){
            if(i>lm) ans += solve(len-1,k-1,i,m);
            else ans += solve(len-1,k,lm,m);
        }
        return dp[len][k][lm] = ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,0,m);
    }
};