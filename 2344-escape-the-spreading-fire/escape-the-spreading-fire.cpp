class Solution {
public:
    int dr[5] = {0, 1, 0, -1, 0};

    bool isValid(int n,int m,int x,int y){
        if(x >= n || y >= m || x < 0 || y < 0)
            return false;
        return true;
    }

    int maximumMinutes(vector<vector<int>>& grid) {

        //for each tile get the earliest time fire will reach it using BFS
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> fireTime (n,vector<int> (m,INT_MAX));
        vector<vector<bool>> vis (n,vector<bool> (m));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                    fireTime[i][j] = 0;
                }
                else if(grid[i][j] == 2){
                    //marking wall as visited so we don't push it to queue
                    vis[i][j] = 1;
                }
            }
        } 

        while(!q.empty()){
            pair<int,int> cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;
            for(int i=0;i<4;i++){
                if(isValid(n, m, x + dr[i], y + dr[i+1]) && !vis[x+dr[i]][y+dr[i+1]]){
                    fireTime[x+dr[i]][y+dr[i+1]] = fireTime[x][y] + 1;
                    vis[x+dr[i]][y+dr[i+1]] = 1;
                    q.push({x+dr[i],y+dr[i+1]});
                }
            }
        }  

        auto check = [&](int time) {

            vector<vector<bool>> visDFS (n,vector<bool> (m));

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] == 2){
                        //marking walls as visited 
                        visDFS[i][j] = 1;
                    }
                }
            }

            //try out all paths with DFS
            function<bool(int,int,int)> dfs = [&](int x,int y,int fireTimeFromOrigin) {
                if(x == n-1 && y == m-1) {
                    // first check if reached or not then check for fire
                    if(fireTime[x][y] >= time + fireTimeFromOrigin)
                        return true;
                    return false;
                }
                if(fireTime[x][y] <= time + fireTimeFromOrigin) return false;;
                visDFS[x][y] = 1;
                bool result = 0;
                for(int i=0;i<4;i++){
                    if(isValid(n, m, x + dr[i], y + dr[i+1]) && !visDFS[x+dr[i]][y+dr[i+1]]){
                        result |= dfs(x+dr[i],y+dr[i+1], fireTimeFromOrigin + 1);
                    }
                }
                return result;
            };
            
            return dfs(0,0,0);
        };

        //binary search on time stayed
        int l = 0;
        int r = 1e9;
        int maxTime = -1;
        while(r >= l){
            int mid = l + (r - l) / 2;
            if(check(mid)){
                maxTime = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return maxTime;
    }
};