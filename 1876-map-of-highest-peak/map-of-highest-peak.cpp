class Solution {
public:
    int n,m;
    vector<vector<int>> ans;
    vector<int> dr = {-1,0,1,0},dc = {0,-1,0,1};
    void dfs(int r,int c,int h){
        ans[r][c] = h;
        for(int i = 0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && (ans[nr][nc]>h+1 || ans[nr][nc]==-1)){
                dfs(nr,nc,h+1);
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& iw) {
        n = iw.size();
        m = iw[0].size();
        ans.resize(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(iw[i][j]==1){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int r = it.first,c = it.second;
            for(int i = 0;i<4;i++){
                int nr = r + dr[i],nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && (ans[nr][nc]==-1 || ans[nr][nc]>1+ans[r][c])){
                    ans[nr][nc] = 1+ans[r][c];
                    q.push({nr,nc});
                }
            }
        }
        return ans;

    }
};