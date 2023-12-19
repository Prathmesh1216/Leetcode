class Solution {
public:
    int n,m;
    bool isValid(int r,int c){
        return (r<n && r>=0 && c>=0 && c<m);
    }
    int avg(vector<vector<int>>& img,int r,int c){
        int cnt = 0;
        int sum = 0;
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
                int nr = r + i, nc = c + j;
                if(isValid(nr,nc)) sum += img[nr][nc],cnt++; 
            }
        }
        return sum/cnt;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans[i][j] = avg(img,i,j);
            }
        }
        return ans;
    }
};