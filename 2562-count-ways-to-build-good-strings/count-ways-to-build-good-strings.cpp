class Solution {
public:
    long long m = 1e9+7;
    long long dp[100001];
    long long solve(int n,int zero,int one){
        long long ans = 1;
        if(dp[n]!=-1) return dp[n]%m;
        dp[n] = 1;
        if(n-zero>=0) dp[n] += solve(n-zero,zero,one);
        if(n-one>=0) dp[n] +=   solve(n-one,zero,one);
        return dp[n];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        long long ans1 = solve(high,zero,one);
      //  cout << ans1 << endl;

        memset(dp,-1,sizeof(dp));
        long long ans2 = solve(low-1,zero,one);
       // cout << ans2 << endl;
        return (ans1-ans2)%m;
    }
};