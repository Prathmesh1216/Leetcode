class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(grid[r][c]){
                    if(r-1<0 || grid[r-1][c]==0) ans++;
                    if(r+1>=n || grid[r+1][c]==0) ans++;
                    if(c-1<0 || grid[r][c-1]==0) ans++;
                    if(c+1>=m || grid[r][c+1]==0) ans++;
                }
            }
        }
        return ans;
    }
};