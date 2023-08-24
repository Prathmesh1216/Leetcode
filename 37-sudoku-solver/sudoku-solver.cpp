class Solution {
public:
    bool mf = false;
    bool isValid(int x,int r,int c,vector<vector<char>>& board){
        for(int i = 0;i<9;i++){
            if(board[i][c]==x+'0') return false;
            if(board[r][i]==x+'0') return false;
        }
        for(int a = r/3*3;a<(r/3*3+3);a++){
            for(int b = c/3*3;b<(c/3*3+3);b++){
                if(board[a][b]== x + '0') return false;
            }
        }
        return true;
    }
    void solve(vector<vector<char>>& board,int r,int c){
        if(mf) return;
        if(r==9){
            mf = true;
            return;
        }
        if(c==9){
            solve(board,r+1,0);
        }
        else{
            if(board[r][c]!='.'){
                solve(board,r,c+1);
                if(mf) return;
            }
            else{
                for(int x = 1;x<=9;x++){
                    if(isValid(x,r,c,board)){
                        board[r][c] = x + '0';
                        solve(board,r,c+1);
                        if(mf) return;
                        board[r][c] = '.';
                    }
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);

    }
};