class Solution {
public:
    int n;
    const int mod = 1e9+7;
    vector<vector<int>> moves = {{-1,-1},{-1,0},{0,-1}};
    // bool isValid(int r,int c,vector<string>& board){
    //     if(r<0 || r>=n || c<0 || c>=n || board[r][c]=='X') return false;
    //     return true;
    // }
    // int ways(int r,int c,int csum,vector<string>& board){
    //     if(r==0 && c==0 && csum==0) return 1;
    //     if(csum==0 && ((r-1==0 && c==0) || (r==0 && c-1==0) || (r-1==0 && c-1==0))) return 1;
    //     if((r==0 && c==0) || csum<=0) return 0;
    //     if(dp1[r][c][csum]!=-1) return dp1[r][c][csum];
    //     long long ans = 0;
    //     int nsum = csum;
    //     if(isdigit(board[r][c])) nsum -= (board[r][c]-'0');
    //     for(auto& it : moves){
    //         int nr = r + it[0], nc = c + it[1];
    //         if(isValid(nr,nc,board)) ans += ways(nr,nc,nsum,board)%mod;
    //     }
    //     return dp1[r][c][csum] = ans%mod;
    // }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        //dp.resize(n+1,vector<int>(n+1,-1));
      //  int maxsum = maxSum(n-1,n-1,board);
        vector<vector<long long>> score(n+1,vector<long long>(n+1)),ways(n+1,vector<long long>(n+1));
        board[0][0] = board[n-1][n-1] = '0';
        ways[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(board[i-1][j-1]=='X') continue;
                for(auto& it : moves){
                    int ni = i + it[0],nj = j + it[1];
                    int cs = score[ni][nj] + (board[i-1][j-1]-'0');
                    if(score[i][j]<cs){
                        ways[i][j] = ways[ni][nj];
                        score[i][j] = cs;
                    }
                    else if(score[i][j]==cs){
                        ways[i][j] = (ways[i][j] + ways[ni][nj])%mod;
                    }
                }
            }
        }
        return {(ways[n][n]==0)?0:(int)score[n][n]%mod,(int)ways[n][n]%mod};
    }
};