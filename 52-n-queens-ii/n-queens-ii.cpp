class Solution {
public:
    int n;
    bool isValid(int r,int c,vector<vector<bool>>& grid){
        for(int j = 0;j<n;j++){
            if(grid[r][j]==1) return false; 
        }
        for(int i = 0;i<n;i++){
            if( grid[i][c]==1) return false;
        }
        int i = r,j = c;
        while(i>=0 && j>=0){
            if(grid[i][j]==1) return false;
            i--;
            j--;
        }
        i = r,j = c;
        while(i>=0 && j<n){
            if(grid[i][j]==1) return false;
            i--;
            j++;
        }
        i = r,j = c;
        while(i<n && j>=0){
            if(grid[i][j]==1) return false;
            i++;
            j--;
        }
        i = r,j = c;
        while(i<n && j<n){
            if(grid[i][j]==1) return false;
            i++;
            j++;
        }
        return true;
    }
    int solve(int j,vector<vector<bool>>& grid){
        if(j==n) return 1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(isValid(i,j,grid)){
                grid[i][j] = 1;
                ans += solve(j+1,grid);
                grid[i][j] = 0;
            }
        }
        return ans;
    }
    int totalNQueens(int N) {
        n = N;
        vector<vector<bool>> grid(n,vector<bool>(n,0));
        return solve(0,grid);
    }
};