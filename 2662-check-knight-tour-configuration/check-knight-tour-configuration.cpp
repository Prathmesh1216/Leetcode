class Solution {
public:
    vector<vector<int>> moves = {{1,2},{2,1},{-1,2},{-2,1},{-1,-2},{-2,-1},{1,-2},{2,-1}};
    int n;
    bool dfs(int r,int c,vector<vector<int>>& grid,int steps){
        if(steps == n*n-1) return true;
        for(int i = 0;i<8;i++){
            int nr = r + moves[i][0],nc = c + moves[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==steps+1) return dfs(nr,nc,grid,steps+1);
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0]!=0) return false;
        return dfs(0,0,grid,0);
    }
};