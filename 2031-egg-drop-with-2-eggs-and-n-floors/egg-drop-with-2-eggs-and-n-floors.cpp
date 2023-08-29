class Solution {
public:
    int nn;
    int dp[1001][3];
    int solve(int e,int f){
        if(dp[f][e]!=-1) return dp[f][e];
        if(e==0 || f==0) return 0;
        if(e==1) return f;
        if(f==1) return 1;
        int ans = 123456789;
        for(int i = 1;i<=f;i++){
            ans = min(ans,max(solve(e-1,i-1),solve(e,f-i)));
        }
        return dp[f][e] = 1+ans;
    } 
    int twoEggDrop(int n) {
        nn = n;
        memset(dp,-1,sizeof(dp));
        return solve(2,n);
    }
};