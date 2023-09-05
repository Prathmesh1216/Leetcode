class Solution {
public:
    queue<pair<pair<int,int>,int>> q;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    int n,m;
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        vis[r][c] = 1;
        q.push({{r,c},0});
        for(int i = 0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]) dfs(nr,nc,grid,vis);
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = INT_MAX;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        bool flag = false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
               if(!flag && grid[i][j]==1){
                   dfs(i,j,grid,vis);
                   flag = true;
               } 
            }
        }
        cout << q.size() << endl;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int d = it.second;
            if(!vis[r][c] && grid[r][c]==1){
                ans = min(ans,d);
                continue;
            }
            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    if(grid[nr][nc]==0) vis[nr][nc] = 1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return ans-1;
    }
};