class Solution {
public:
    int n,m;
    vector<vector<bool>> vis;
    int solve(int steps,int r,int c,int er,int ec,vector<vector<int>>& grid,int ecnt){
        if(r==er && c==ec){
            if(steps==ecnt) return 1;
            return 0;
        }
        vis[r][c] = 1;
        int cnt = 0;
        if(grid[r][c]==0) steps = steps+1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        bool flag = false;
        for(int k = 0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr>=0 && nr< n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]!=-1) cnt +=solve(steps,nr,nc,er,ec,grid,ecnt);
        }
        vis[r][c] = 0;
        return cnt;


    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n,vector<bool>(m,0));
        int ecnt = 0;
        int sr,sc,er,ec;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    sr = i;
                    sc = j;
                }
                else if(grid[i][j]==2){
                    er = i;
                    ec = j;
                }
                else if(grid[i][j]==0) ecnt++;
            }
        }
        return solve(0,sr,sc,er,ec,grid,ecnt);
    }
};