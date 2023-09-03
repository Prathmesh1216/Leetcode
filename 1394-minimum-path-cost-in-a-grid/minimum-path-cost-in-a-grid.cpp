class Solution {
public:
    int n;
    int m;
    int dp[51][51];
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& moveCost){
        if(i==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 123456789;
        for(int k = 0;k<m;k++){
            ans = min(ans,grid[i][j]+moveCost[grid[i][j]][k]+solve(i+1,k,grid,moveCost));
        }
        return dp[i][j] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 123456789;
        for(int j = 0;j<m;j++){
            ans = min(ans,solve(0,j,grid,moveCost));
        }
        return ans;
    }
};