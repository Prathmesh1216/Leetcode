class Solution {
public:
    string longestPalindrome(string s) {
        string t = s;
        int n = s.length();
        int len = 0;
        string res = "";
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(len < dp[i][j]){
                        string tmp1 = s.substr(i-dp[i][j], dp[i][j]);
                        string tmp2 = string(tmp1.rbegin(), tmp1.rend());
                        if(tmp1 == tmp2){
                            len = dp[i][j];
                            res = tmp1;
                        }
                    }
                }
                else dp[i][j] = 0;
            }
        }
        return res;
    }
};