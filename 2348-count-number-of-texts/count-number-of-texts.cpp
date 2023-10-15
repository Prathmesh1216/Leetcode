class Solution {
public:
   vector<int> mappings = {0,0,3,3,3,3,3,4,3,4};
    int n;
    int mod = 1e9+7;
    long long dp[100001];
    long long solve(int i,string& pk){
        if(i>=pk.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        long long ans = 0;
        for(int j = i;j<=min(mappings[pk[i]-'0']+i-1,n-1);j++){
            if(pk[j]!=pk[i]) break;
            ans += solve(j+1,pk);
        }
        return dp[i] = ans%mod;
    }
    int countTexts(string& pk) {
        n = pk.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,pk)%mod;
    }
};