class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i-1>=0 && mat[i-1][j]>=mat[i][j]) || (i+1<n && mat[i+1][j]>=mat[i][j]) || (j-1>=0 && mat[i][j-1]>=mat[i][j]) || (j+1<m && mat[i][j+1]>=mat[i][j])) continue;
                return {i,j};
            }
        }
        return {-1,-1};
    }
};