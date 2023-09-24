class Solution {
public:
    double champagneTower(int poured, int ti, int tj ){
        vector<vector<double>> dp(102,vector<double>(102,0));
        dp[0][0] = poured;
        for(int i = 1;i<=ti;i++){
            for(int j = 0;j<=tj;j++){
                double of = max(dp[i-1][j]-1,0.0);
                dp[i][j] += of/2.0;
                dp[i][j+1] += of/2.0;


            }
        }
        return min(dp[ti][tj],1.0);

    }
};