class Solution {
public:
    int tm,n,m;
    unordered_map<char,int> mp;
    vector<vector<int>> moves = {{0,-1},{0,1},{1,0},{-1,0}};
    bool isValid(int r,int c,vector<string>& grid){
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]!='#') return true;
        return false; 
    }
    // int solve(int r,int c,int km,vector<vector<vector<bool>>>& vis,vector<string>& grid){
    //     if(km == tm) return true;
    //     int ans = 123456789;
    //    vis[r][c][km] = 1;
    //     for(int i = 0;i<4;i++){
    //         int nr = r + moves[i][0],nc = c + moves[i][1];
    //         if(isValid(nr,nc,grid) && !vis[nr][nc][km|(1<<mp[grid[nr][nc]])] && mp.find(grid[nr][nc])!=mp.end() && islower(grid[nr][nc])){
    //             ans = min(ans,1+solve(nr,nc,km|(1<<mp[grid[nr][nc]]),vis,grid));
    //         }
    //         else if(isValid(nr,nc,grid) && !vis[nr][nc][km] && isupper(grid[nr][nc])){
    //             char ch = tolower(grid[nr][nc]);
    //             if(mp.find(ch)!=mp.end() && km&(1<<mp[ch])) ans = min(ans,1+solve(nr,nc,km,vis,grid));
    //         }
    //         else if(isValid(nr,nc,grid) && !vis[nr][nc][km]) ans = min(ans,1+solve(nr,nc,km,vis,grid));
    //     }
    //     vis[r][c][km] =0;
    //     return  ans;
    // }
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size(); m = grid[0].size();
        int k = 0,sr,sc,l = 0;
       for(int i = 0;i<n;i++){
           for(int j = 0;j<m;j++){
               if(grid[i][j]=='@'){
                   sr = i; sc = j;
               }
               else if(iswalnum(grid[i][j]) && islower(grid[i][j])) mp[grid[i][j]] = l,l++,k++;
           }
       }
       tm = (1<<k)-1;
       grid[sr][sc] = '.';
       vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(1<<6)));
       queue<vector<int>> q;
       vis[sr][sc][0] = 1;
       q.push({sr,sc,0,0});
       while(!q.empty()){
           auto& v = q.front(); int r = v[0],c = v[1],km = v[2],steps = v[3];q.pop();
           if(km==tm) return steps;
           for(auto& it : moves){
            int nr = r + it[0],nc = c + it[1];
            if(isValid(nr,nc,grid) && !vis[nr][nc][km|(1<<mp[grid[nr][nc]])] && mp.find(grid[nr][nc])!=mp.end() && islower(grid[nr][nc])){
                vis[nr][nc][km|(1<<mp[grid[nr][nc]])] = 1;
                q.push({nr,nc,km|(1<<mp[grid[nr][nc]]),steps+1});
            }
            else if(isValid(nr,nc,grid) && !vis[nr][nc][km] && isupper(grid[nr][nc])){
                char ch = tolower(grid[nr][nc]);
                if(mp.find(ch)!=mp.end() && km&(1<<mp[ch])){
                    q.push({nr,nc,km,steps+1});
                    vis[nr][nc][km] = 1;
                } 
            }
            else if(isValid(nr,nc,grid) && !vis[nr][nc][km]){
                vis[nr][nc][km] = 1;
                q.push({nr,nc,km,steps+1});
                }
            }
        }               
        return -1;
    }
};