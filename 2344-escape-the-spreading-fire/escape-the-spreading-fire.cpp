class Solution {
public:
    vector<vector<int>> ft;
    vector<vector<int>> dis;
    int n,m;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,-1,0,1};
    bool isValid(int r,int c){
        if(r>=0 && r<n && c>=0 && c<m) return true;
        return false;
    }
    bool isvalid(int mid,vector<vector<int>>& grid){
        queue<vector<int>> pq;
        pq.push({0,0,mid});
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int r = it[0];
            int c = it[1];
            if(r==n-1 && c==m-1) return true;
            int time = it[2];
            vis[r][c] = 1;
            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr,nc) && grid[nr][nc]!=2 && !vis[nr][nc] && (time+1<ft[nr][nc] || (nr==n-1 && nc==m-1 && time+1<=ft[nr][nc]))) pq.push({nr,nc,time+1});
            }

        }
        return false;

    }
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> pq;
        ft.resize(n,vector<int>(m,INT_MAX-1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    pq.push({i,j});
                    ft[i][j] = 0;
                }
            }
        }
        while(!pq.empty()){
            auto it = pq.front();
            int r = it.first;
            int c = it.second;
            pq.pop();
            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr,nc) && grid[nr][nc]!=2 && ft[nr][nc]>ft[r][c]+1){
                    ft[nr][nc] = 1 + ft[r][c];
                    pq.push({nr,nc});
                }
            }
        }
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         cout << ft[i][j] << " " ;
        //     }
        //     cout << endl;
        // }
        int start = 0;
        int end = 1e9;
        int ans = -1;
       // if(isvalid(1e9,grid)) return 1e9;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isvalid(mid,grid)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
};