class Solution {
public:
    int n,m;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i == n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 123456789;
        int temp = grid[i][j];
        for(int  jj = 0;jj<m;jj++){
           // cout << " here" ;
            if(j!=jj) ans = min(ans,temp + solve(i+1,jj,grid));
        }
        return dp[i][j]= ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
      //  cout << m << endl;
        memset(dp,-1,sizeof(dp));
        int ans = 123456789;
        for(int i = 0;i<m;i++){
            ans  = min(ans,solve(0,i,grid));
        }
        return ans;
    }
};