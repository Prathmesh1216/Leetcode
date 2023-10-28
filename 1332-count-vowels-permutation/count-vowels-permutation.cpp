class Solution {
public:
    int n;
    long long dp[20001][6];
    int m = 1e9+7;
    long long solve(int i,int v){
        if(i==n) return 1;
        if(dp[i][v]!=-1) return dp[i][v];
        if(!v) return dp[i][v] = (solve(i+1,1) + solve(i+1,2) + solve(i+1,3) + solve(i+1,4) + solve(i+1,5))%m;
        if(v==1) return dp[i][v] = solve(i+1,2)%m;
        if(v==2) return dp[i][v] = (solve(i+1,1)%m + solve(i+1,3)%m)%m;
        if(v==3) return dp[i][v] = (solve(i+1,1) + solve(i+1,2) + solve(i+1,4) + solve(i+1,5))%m;
        if(v==4) return dp[i][v] = (solve(i+1,3) + solve(i+1,5))%m;
        return dp[i][v] = solve(i+1,1)%m;
    }
    int countVowelPermutation(int N) {
        n = N;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};