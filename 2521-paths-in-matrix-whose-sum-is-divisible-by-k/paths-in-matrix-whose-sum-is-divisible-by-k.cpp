class Solution {
public:
    int n;
    int m;
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,int sum,vector<vector<int>>& grid,int k){
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j == m-1){
            if((sum+grid[i][j])%k==0) return 1;
            return 0;
        }
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        return dp[i][j][sum] = (solve(i+1,j,(sum+grid[i][j])%k,grid,k)%mod+solve(i,j+1,(sum+grid[i][j])%k,grid,k)%mod)%mod;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                grid[i][j] %= k;
            }
        }
        return solve(0,0,0,grid,k);
    }
};