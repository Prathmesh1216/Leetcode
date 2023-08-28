class Solution {
public:
    int mod = 1e9+7;
    int countHousePlacements(int n) {
        if(n==1) return 4;
        vector<int> dp(n);
        dp[0] = 2;
        dp[1] = 3;
        for(int i = 2;i<n;i++){
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        long long ans = dp[n-1]*1LL*dp[n-1];
        return (ans)%mod;
    }
};