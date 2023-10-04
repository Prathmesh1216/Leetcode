class Solution {
public:
    int n,m;
    bool isValid(int i,int j,vector<vector<int>>& grid){
        if(i>=n || j>=m || grid[i][j]==-1) return false;
        return true;
    }
    int dp[51][51][51][51];
    vector<vector<int>> moves = {{1,0},{0,1}};
    int solve(int i1,int j1,int i2,int j2,vector<vector<int>>& grid){
        if(i1==n-1 && i2==n-1 && j1==m-1 && j2==m-1) return grid[i1][j1];
        if(dp[i1][i2][j1][j2]!=-1) return dp[i1][i2][j1][j2];
        int ans = 0;
        if(i1==i2 && j1==j2) ans += grid[i1][j1];
        else ans += grid[i1][j1] + grid[i2][j2];
        int fans = -123456789;
        if(isValid(i1+1,j1,grid) && isValid(i2+1,j2,grid)) fans = max(fans,ans + solve(i1+1,j1,i2+1,j2,grid));
        if(isValid(i1,j1+1,grid) && isValid(i2+1,j2,grid)) fans = max(fans,ans + solve(i1,j1+1,i2+1,j2,grid));
        if(isValid(i1+1,j1,grid) && isValid(i2,j2+1,grid)) fans = max(fans,ans + solve(i1+1,j1,i2,j2+1,grid));
        if(isValid(i1,j1+1,grid) && isValid(i2,j2+1,grid)) fans = max(fans,ans + solve(i1,j1+1,i2,j2+1,grid));
        return dp[i1][i2][j1][j2] = fans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return (solve(0,0,0,0,grid)<=0)?0:solve(0,0,0,0,grid);
    }
};