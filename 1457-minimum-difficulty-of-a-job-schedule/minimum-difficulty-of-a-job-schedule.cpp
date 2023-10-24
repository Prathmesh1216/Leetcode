class Solution {
public:
    int n;
    int dp[301][11];
    int solve(int i,int d,vector<int>& jd){
        if(i==n && d==0) return 0;
        if(i==n || d==0) return 123456789;
        if(dp[i][d]!=-1) return dp[i][d];
        int m = 0;
        int ans = 123456789;
        for(int j = i;j<jd.size();j++){
            m = max(m,jd[j]);
            ans = min(ans, m+ solve(j+1,d-1,jd));
        }
        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,d,jd);
        return (ans>=123456789)?-1:ans;
    }
};