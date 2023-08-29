class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> ps(2,vector<long long>(n,0));
     //   int ans = 0;
        ps[0][0] = grid[0][0];
        ps[1][0] = grid[1][0];
        for(int i = 0;i<2;i++){
            for(int j = 1;j<n;j++){
                ps[i][j] =grid[i][j] + ps[i][j-1];
            }
        }
        long long ans = LONG_MAX;
        for(int j = 0;j<n;j++){
            ans = min(ans,max(ps[0][n-1]-ps[0][j],ps[1][j]-grid[1][j]));
        }
        return ans;
    }
};