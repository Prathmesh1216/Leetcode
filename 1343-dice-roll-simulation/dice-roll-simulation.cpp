class Solution {
public:
    int dp[5001][16][8];
    int mod = 1e9+7;
    int solve(int n,int cnt,int le,vector<int>& rollMax){
        if(n==0) return 1;
        if(dp[n][cnt][le+1]!=-1) return dp[n][cnt][le+1];
        long long ans = 0;
        for(int i = 0;i<6;i++){
            if(i+1!=le) ans+= solve(n-1,1,i+1,rollMax);
            else if(rollMax[i]>cnt) ans+= solve(n-1,cnt+1,i+1,rollMax);
        }
        return dp[n][cnt][le+1] = ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,-1,rollMax);
    }
};