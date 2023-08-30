class Solution {
public:
    int n,m;
    vector<vector<int>> dist;
    bool isValid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m) return true;
        return false;
    }
    bool Valid(int r,int c,int dr[],int dc[],int mid){
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(dist[r][c]>=mid) q.push({r,c});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n-1 && y==m-1) return true;
            for(int i = 0;i<4;i++){
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(isValid(nr,nc) && !vis[nr][nc] && dist[nr][nc]>=mid){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        dist.resize(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    dist[i][j] = 0;
                    pq.push({0,i,j});
                }
            }
        }
        while(!pq.empty()){
            int dis = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(isValid(nrow,ncol) && dist[nrow][ncol]>1+dist[row][col]){
                    dist[nrow][ncol] = 1 + dist[row][col];
                    pq.push({dist[nrow][ncol],nrow,ncol});
                }
            }
        }
        int start = 0;
        int end = max(n,m);
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(Valid(0,0,drow,dcol,mid)){
                ans  = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
        
    }
};