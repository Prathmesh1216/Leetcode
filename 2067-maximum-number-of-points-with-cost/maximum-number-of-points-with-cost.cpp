class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        for(int j = 0;j<m;j++){
            dp[0][j] = points[0][j];
        }
        for(int i = 1;i<n;i++){
            vector<long long> left(m),right(m);
            left[0] = dp[i-1][0];
            for(int c = 1;c<m;c++){
                left[c] = max(left[c-1],dp[i-1][c]+c);
            }
            right[m-1] = dp[i-1][m-1] - (m-1);
            for(int c = m-2;c>=0;c--){
                right[c] = max(right[c+1],dp[i-1][c]-c);
            }
            for(int c = 0;c<m;c++){
                dp[i][c] = points[i][c] + max(left[c]-c,right[c]+c);
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};