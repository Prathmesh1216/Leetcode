class Solution {
public:
void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis){
    int n=grid.size();
    int m=grid[0].size();
    if(r<0 || c<0 || r>=n || c>=m || vis[r][c] || grid[r][c]==0) return ;
    vis[r][c]=1;
    int row[]={0,-1,0,1};
    int col[]={-1,0,1,0};
    for(int i=0;i<4;i++){
        int nr=r+row[i];
        int nc=c+col[i];
        dfs(nr,nc,grid,vis);
    }
return;
}
int bfs(vector<vector<int>> &vis,vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]) q.push({i,j});
        }
    }
    int cnt=0;
    while(!q.empty()){
        int a=q.size();
       
        while(a--){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
             int row[]={0,-1,0,1};
             int col[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc<m && nc>=0 && !vis[nr][nc]){
                    if(grid[nr][nc]==1) return cnt;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        cnt++;
    }
    return cnt;
}
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));
      
      
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(!vis[i][j] && grid[i][j]==1){
                  dfs(i,j,grid,vis);
                  return bfs(vis,grid);
              }
          }
      }
       return -1; 
    }
};