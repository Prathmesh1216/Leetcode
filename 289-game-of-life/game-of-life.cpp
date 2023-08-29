class Solution {
public:
    int n;
    int m;
    bool isValid(int i,int j){
        if(i<0 || j<0 ||j>=m ||i>=n) return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
         n = board.size();
         m = board[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = -1;k<=1;k++){
                    for(int kk = -1;kk<=1;kk++){
                        if(isValid(i+k,j+kk) && (j+kk!=j || i+k!=i)){
                            if(board[i+k][j+kk]==1) v[i][j]++;
                        }
                    }
                }
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]==1){
                    if(v[i][j]<2) board[i][j] = 0;
                    else if(v[i][j]>3) board[i][j] = 0;
                }
                else{
                    if(v[i][j]==3) board[i][j] = 1;
                } 
            }
        }
    }
};