class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    dist[i][j] = 0;
                    pq.push({i,j});
                }
            }
        }
        if(pq.empty()) return -1;
        if(pq.size()==n*m) return -1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!pq.empty()){
            auto it  = pq.front();
            int r = it.first;
            int c = it.second;
            pq.pop();
            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]>1+dist[r][c]){
                    dist[nr][nc] = 1 + dist[r][c];
                    pq.push({nr,nc});
                }
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans = max(ans,dist[i][j]);
            }
        }
        return ans;

    }
};