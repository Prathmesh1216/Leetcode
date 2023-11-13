class Solution {
public:
    vector<vector<int>> moves = {{-1,0},{0,-1},{1,0},{0,1}};
    int n,m;
    bool isValid(int r,int c,int nr,int nc,vector<vector<int>>& matrix){
        if(nr<0 || nr>=n || nc<0 || nc>=m || matrix[nr][nc]<=matrix[r][c]) return false;
        return true;
    }
    int dp[201][201];
    int solve(int r,int c,vector<vector<int>>& matrix){
        int ans = 1;
        if(dp[r][c]!=-1) return dp[r][c];
        for(auto& it : moves){
            int nr = r + it[0],nc = c + it[1];
            if(isValid(r,c,nr,nc,matrix)) ans = max(ans,1+solve(nr,nc,matrix));
        }
        return dp[r][c] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(),m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans;

    }
};