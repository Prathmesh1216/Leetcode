class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i,int j,string &s,string& t){
        if(j==m) return n-i;
        if(i==n) return m-j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = solve(i+1,j+1,s,t);
        return dp[i][j] = 1 + min({solve(i+1,j+1,s,t),solve(i+1,j,s,t),solve(i,j+1,s,t)});
    }
    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};