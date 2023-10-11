class Solution {
public:
    // wall -> -1 ; guard -> 1;
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(n,vector<int>(m,0)),vec(n,vector<int>(m,0));
        int cnt = 0;
        for(auto& it : walls){
            grid[it[0]][it[1]] = -1;
            vec[it[0]][it[1]] = -1;
        }
        for(auto& it : guards){
            grid[it[0]][it[1]] = 1;
            vec[it[0]][it[1]] = 1;
        }
        for(int i = 0;i<n;i++){
            int last = 0;
            for(int j = 0;j<m;j++){
                if(grid[i][j]==-1){
                    last = -1;
                }
                else if(grid[i][j]==1){
                    last = 1;
                }
                else{
                    if(last==1) vec[i][j] = 1;
                }
            }
            last = 0;
            for(int j = m-1;j>=0;j--){
                if(grid[i][j]==-1){
                    last = -1;
                }
                else if(grid[i][j]==1){
                    last = 1;
                }
                else{
                    if(last==1) vec[i][j] = 1;
                }
            }
            
        }
        for(int j = 0;j<m;j++){
            int last = 0;
            for(int i = 0;i<n;i++){
                if(grid[i][j]==-1){
                    last = -1;
                }
                else if(grid[i][j]==1){
                    last = 1;
                }
                else{
                    if(last==1) vec[i][j] = 1;
                }
            }
            last = 0;
            for(int i = n-1;i>=0;i--){
                if(grid[i][j]==-1){
                    last = -1;
                }
                else if(grid[i][j]==1){
                    last = 1;
                }
                else{
                    if(last==1) vec[i][j] = 1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vec[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};