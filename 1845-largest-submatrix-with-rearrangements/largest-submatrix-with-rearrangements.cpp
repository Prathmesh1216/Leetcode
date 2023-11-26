class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]!=0) matrix[i][j] += matrix[i-1][j];
            }
        }
        int ans = 0;
        for(auto& it : matrix){
            sort(it.rbegin(),it.rend());
            int t = 123456789;
            for(int j = 0;j<m;j++){
                if(it[j]==0) continue;
                t = min(t,it[j]);
                int area = (j+1)*t;
                ans = max(ans,area);
            }
        }
        return ans;
    }
};