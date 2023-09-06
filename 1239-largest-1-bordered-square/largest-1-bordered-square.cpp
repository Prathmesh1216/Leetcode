class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rsum(n,vector<int>(m,0));
        vector<vector<int>> csum(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            rsum[i][0] = grid[i][0];
            for(int j = 1;j<m;j++){
                rsum[i][j] = rsum[i][j-1]+grid[i][j];
            }
        }
        for(int j = 0;j<m;j++){
            csum[0][j] = grid[0][j];
            for(int i = 1;i<n;i++){
                csum[i][j] = csum[i-1][j]+grid[i][j];
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int a = i;
                int b = j;
                while(a<n && b<m){
                    if(rsum[i][b]-rsum[i][j]+grid[i][j]==b-j+1 && rsum[a][b]-rsum[a][j]+grid[a][j]==b-j+1 && csum[a][j]-csum[i][j]+grid[i][j]==b-j+1 && csum[a][b]-csum[i][b]+grid[i][b]==b-j+1) ans = max(ans,(b-j+1)*(b-j+1));
                    a++;
                    b++;
                }
            }
        }
        return ans;
    }
};