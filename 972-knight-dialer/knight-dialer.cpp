class Solution {
public:
    int mod = 1e9+7;
    int dp[4][3][5001];
    bool isValid(int i,int j){
        if(i==3 && (j==0 || j==2)) return false;
        if(i>=0 && i<4 && j>=0 && j<3) return true;
        return false; 
    }
    long long solve(int i,int j,int d,int n){
        if(d==n-1){
            return 1;
        }
        long long res = 0;
        if(dp[i][j][d]!=-1) return dp[i][j][d]; 
        int drow[] = {-2,-2,-1,-1,1,1,2,2};
        int dcol[] = {-1,1,2,-2,2,-2,1,-1};
        for(int k = 0;k<8;k++){
            int ni = i + drow[k];
            int nj = j + dcol[k];
            if(isValid(ni,nj)) res += solve(ni,nj,d+1,n);
        }
        return dp[i][j][d] = res%mod;


    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        long long ans = 0;
        for(int i = 0;i<4;i++){
            for(int j = 0;j<3;j++){
                if(isValid(i,j)){
                    ans += solve(i,j,0,n);
                }
            }
        }
        return ans%mod;
    }
};