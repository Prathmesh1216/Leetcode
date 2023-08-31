class Solution {
public:
    int dp[10001][7][7];
    int mod = 1e9+7;
    int solve(int n,int l,int sl){
        if(n==0) return 1;
        if(dp[n][l][sl]!=-1) return dp[n][l][sl];
        long long ans = 0;
        for(int i = 1;i<=6;i++){
            if(i!=l && i!=sl && (l==0||__gcd(i,l)==1)) ans += solve(n-1,i,l);
        }
        return dp[n][l][sl] = ans%mod;
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};