class Solution {
public:
    int n,m;
    vector<vector<int>> moves = {{0,-1},{0,1},{1,0},{-1,0}};
    vector<vector<bool>> vis;
    void dfs(int r,int c,int pc,int color,vector<vector<int>>& grid){
        vis[r][c] = 1;
        if(r==0 || c==0 || r==n-1 || c==m-1) grid[r][c] = color;
        if((r+1<=n-1 && grid[r+1][c]!=pc && !vis[r+1][c]) || (r-1>=0 && grid[r-1][c]!=pc && !vis[r-1][c]) || (c+1<=m-1 && grid[r][c+1]!=pc && !vis[r][c+1]) || (c-1>=0 && grid[r][c-1]!=pc && !vis[r][c-1])) grid[r][c] = color;
        for(int i = 0;i<4;i++){
            int nr = r + moves[i][0],nc = c + moves[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==pc && !vis[nr][nc]) dfs(nr,nc,pc,color,grid);
        }
        return;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size(),m = grid[0].size();
        vis.resize(n,vector<bool>(m));
        dfs(row,col,grid[row][col],color,grid);
        return grid;
    }
};