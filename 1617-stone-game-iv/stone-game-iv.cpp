class Solution {
public:
    int dp[100001][2];
    bool solve(int n,int turn){
        if(n==0){
            if(turn) return true;
            return false;
        }
        if(dp[n][turn]!=-1) return dp[n][turn];
        if(!turn){
            bool flag = false;
            for(int i = 1 ;i*i <=n ;i++){
            if(n-i*i>=0){
                flag = flag || solve(n-i*i,1);
            }
        }
        return dp[n][turn] = flag;
        
        }
        bool flag = true;
        for(int i = 1;i*i<=n;i++){
            if(n-i*i>=0){
                flag = flag && solve(n-i*i,0);
            }
        }
        return dp[n][turn] = flag;
        
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};