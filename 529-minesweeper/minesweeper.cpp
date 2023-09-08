class Solution {
public:
    int n,m;
    vector<vector<int>> cnt;
    int count(int r,int c,vector<vector<char>>& board){
        int cnt = 0;
                for(int i = -1;i<=1;i++){
                    for(int j = -1;j<=1;j++){
                        if((i!=0 || j!=0) && r+i>=0 && r+i<n && j+c>=0 && j+c<m){
                            if(board[r+i][c+j]=='M') cnt++;
                        }
                    }
                }
                return cnt;
    }
    void dfs(int r,int c,vector<vector<char>>& board){
        if(board[r][c]=='E'){
            if(cnt[r][c]==0){
                board[r][c] = 'B';
                for(int i = -1;i<=1;i++){
                    for(int j = -1;j<=1;j++){
                        int nr = r + i;
                        int nc = c + j;
                        if(nr>=0 && nr<n && nc>=0 && nc<m && (board[nr][nc]=='M'||board[nr][nc]=='E')){
                            dfs(nr,nc,board);
                        }
                    }
                }
            }
            else if(cnt[r][c]>0){
                board[r][c] =cnt[r][c]+'0';
            }
        }
        return;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
         n = board.size();
         m = board[0].size();
        int r = click[0];
        int c = click[1];
        if(board[r][c]=='M'){
            board[r][c] = 'X';
            return board;
        }
        cnt.resize(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cnt[i][j] = count(i,j,board);
            }
        }
        dfs(r,c,board);
        return board;
    }
};