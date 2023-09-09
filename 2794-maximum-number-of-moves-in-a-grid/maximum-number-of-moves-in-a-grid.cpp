class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(int r,int c,vector<vector<int>>& grid){
        if(r<0 || r>=n || c>=m) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int ans = 0,ans1= 0,ans2 = 0;
        if(c<=m-2 && grid[r][c+1]>grid[r][c]) ans = 1 + solve(r,c+1,grid);
        if(r<=n-2 && c<=m-2 && grid[r+1][c+1]>grid[r][c]) ans1 = 1 + solve(r+1,c+1,grid);
        if(r>0 && c<=m-2 && grid[r-1][c+1]>grid[r][c]) ans2 = 1+solve(r-1,c+1,grid);
        return dp[r][c] = max({ans,ans1,ans2});
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans  = max(ans,solve(i,0,grid));
        }
        return ans;
    }
};