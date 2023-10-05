class Solution {
public:
    int n,m;
    bool isValid(int r,int c){
        if(r>=0 && r<n && c>=0 && c<m) return true;
        return false;
    }
    vector<pair<int,int>> moves = {{0,-1},{0,1},{-1,0},{1,0}}; 
    unordered_map<int,pair<int,int>> mp;
    int minCost(vector<vector<int>>& grid) {
        mp[1] = {0,1};mp[2] = {0,-1};mp[3] = {1,0};mp[4] = {-1,0};
        n  =grid.size();
        m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> cost(n,vector<int>(m,123456789));
        cost[0][0] = 0;
        while(!pq.empty()){
            int r = pq.top().second.first,c = pq.top().second.second;
            pq.pop();
            for(auto& it : moves){
                int nr = r + it.first;int nc = c + it.second;
                int a = 0;
                if(isValid(nr,nc)) a = 1- (mp[grid[r][c]]==it);
                if( isValid(nr,nc) &&  cost[nr][nc] > cost[r][c] + a){
                    cost[nr][nc] = cost[r][c] + !(mp[grid[r][c]]==it);
                    pq.push({cost[nr][nc],{nr,nc}});
                }
            }
        }
        return cost[n-1][m-1];
    }
};