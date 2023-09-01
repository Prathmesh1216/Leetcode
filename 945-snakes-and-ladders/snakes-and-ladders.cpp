class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, pair<int, int>> mp;
        bool flag = false;
        int num = 1;
        for(int i=n-1;i>=0;i--){
            if(flag){
                for(int j=n-1;j>=0;j--){
                    mp[num] = {i, j};
                    num++;
                }
            }
            else{
                for(int j=0;j<n;j++)   {
                    mp[num] = {i, j};
                    num++;
                }
            }
            flag = !flag;
        }
        vector<bool> vis(n*n+1,0);
        queue<pair<int,int>> q;
        q.push({1,0});
        vis[1] = 1;
        while(!q.empty()){
            int num = q.front().first;
            int dist = q.front().second;
            q.pop();
            int x = mp[num].first;
            int y = mp[num].second;
            if(board[x][y]!=-1){
                num = board[x][y];
            }
            if(num==n*n) return dist;
            for(int i = 1;i<=6;i++){
                if(!vis[num+i]){
                    q.push({num+i,dist+1});
                    vis[num+i] = 1;
                }
            }
        }
        return -1;
    }
};