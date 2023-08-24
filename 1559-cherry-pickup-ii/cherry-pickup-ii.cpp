class Solution {
public:
    int n,m;
    int dp[71][71][71];
    int solve(int r,int c1,int c2,vector<vector<int>>& grid){
        if(c1<0 || c2<0 || c1>=m || c2>=m) return -123456789;
        if(r==n-1){
            if(c1==c2) return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int ans = 0;
        if(c1==c2) ans = grid[r][c1];
        else ans = grid[r][c1] + grid[r][c2];
        int temp = INT_MIN;
        for(int k = -1;k<=1;k++){
            for(int kk = -1;kk<=1;kk++){
                temp = max(temp,solve(r+1,c1+k,c2+kk,grid));
            }
        }
        ans += temp;
        return dp[r][c1][c2] = ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,grid);
    }
};