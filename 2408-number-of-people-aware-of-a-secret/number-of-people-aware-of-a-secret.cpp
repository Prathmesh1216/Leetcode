class Solution {
public:
    int dp[1001];
    int m = 1e9+7;
    int solve(int i,int n,int d,int f){
        if(dp[i]!=-1) return dp[i];
        long long ans = 1;
        if(i+f<=n) ans--;
        for(int j = i+d;j<=min(n,f+i-1);j++){
            ans += solve(j,n,d,f)%m;
        }
        return dp[i] = ans%m;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if(delay>=forget) return 1;
        memset(dp,-1,sizeof(dp));
        return solve(1,n,delay,forget);
    }
};