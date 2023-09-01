class Solution {
public:
    int dp[5001][4][4][4];
    int mod = 1e9+7;
    int solve(int i,int pc1,int pc2,int pc3,int n){
        if(i==n) return 1;
        if(dp[i][pc1][pc2][pc3]!=-1) return dp[i][pc1][pc2][pc3];
        long long ans = 0;
        int cc1,cc2,cc3;
        for(int j = 1;j<=3;j++){
            if(pc1!=j){
                cc1 = j;
                for(int jj = 1;jj<=3;jj++){
                    if(pc2!=jj&& cc1!=jj){
                        cc2 = jj;
                        for(int jjj = 1;jjj<=3;jjj++){
                            if(pc3!=jjj&& cc2!=jjj){
                            cc3 = jjj;
                            ans += solve(i+1,cc1,cc2,cc3,n);
                            }
                        }
                    }
                }
            }
        }
        return dp[i][pc1][pc2][pc3] = ans%mod;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,0,n);
    }
};