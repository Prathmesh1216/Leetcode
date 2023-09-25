class NumMatrix {
public:
    vector<vector<int>> ps,rps;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        ps.resize(n,vector<int>(m,0));
        ps[0][0] = matrix[0][0];
        for(int i = 1;i<n;i++){
            ps[i][0] = ps[i-1][0] + matrix[i][0];
        }
        for(int j = 1;j<m;j++){
            ps[0][j] = ps[0][j-1] + matrix[0][j];
        }
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                ps[i][j] = ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1] + matrix[i][j];
            }
        }


    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans = ps[r2][c2];
        if(c1-1>=0) ans -= ps[r2][c1-1];
        if(r1-1>=0) ans -= ps[r1-1][c2];
        if(r1-1>=0 && c1-1>=0) ans += ps[r1-1][c1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */