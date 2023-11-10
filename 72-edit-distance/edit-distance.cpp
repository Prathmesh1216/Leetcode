class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i,int j,string& s,string& t){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n && j==m) return dp[i][j] = 0;
        if(i==n) return dp[i][j] = m-j;
        if(j==m) return dp[i][j] = n-i;
        if(s[i]==t[j]) return dp[i][j] =  solve(i+1,j+1,s,t);
        return dp[i][j] = 1 + min({solve(i+1,j,s,t),solve(i,j+1,s,t),solve(i+1,j+1,s,t)});
    }
    int minDistance(string& s, string& t) {
        n = s.length(); m = t.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};