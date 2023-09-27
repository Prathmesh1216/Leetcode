class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int solve(int i,int steps,int arrLen){
        if(i>500) return 0;
        if(steps==0){
            if(i==0) return 1;
            return 0;
        }
        if(dp[i][steps]!=-1) return dp[i][steps];
        long long ans = solve(i,steps-1,arrLen)%mod;
        if(i-1>=0) ans += solve(i-1,steps-1,arrLen)%mod;
        if(i+1<arrLen) ans += solve(i+1,steps-1,arrLen)%mod;
        return dp[i][steps] = ans%mod;
    }
    int numWays(int steps, int arrLen) {
        dp.resize(501,vector<int>(steps+1,-1));
        return solve(0,steps,arrLen);
    }
};