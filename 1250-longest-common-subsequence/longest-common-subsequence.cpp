class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<m+1;j++){
                if(i==0 || j==0) continue;
                else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};