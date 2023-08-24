class Solution {
public:
    int n;
    int dp[51][51][51][51];
    int solve(int r1,int c1,int r2,int c2,vector<vector<int>>& grid)
{
    if(r1>=n || r2>=n || c1>=n || c2>=n || r1<0 ||r2 <0 || c1<0 || c2< 0 || grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e9;
    
    if(r1==n-1 && c1==n-1)  return grid[r1][c1];
    if(r2==n-1 && c2==n-1) return grid[r2][c2];
    if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
    int ans=0;
    if(r1==r2 && c1==c2) ans=grid[r1][c1];
    else ans=grid[r1][c1]+grid[r2][c2];
    ans +=  max(max(solve(r1+1,c1,r2+1,c2,grid),solve(r1,c1+1,r2,c2+1,grid)),max(solve(r1+1,c1,r2,c2+1,grid),solve(r1,c1+1,r2+1,c2,grid)));
    return dp[r1][c1][r2][c2]= ans;
}

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0]==-1){
            return 0;
        }
        if(grid[n-1][n-1]==-1){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,0,grid);
        if(ans<0) return 0;
        return ans;
    }
};