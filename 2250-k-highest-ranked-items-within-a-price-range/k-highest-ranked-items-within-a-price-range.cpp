class Solution {
public:
    int n,m;
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        if(grid[start[0]][start[1]]==0) return {{}};
        priority_queue<vector<int>> pq;
        n = grid.size();
        m = grid[0].size();
        int low = pricing[0];
        int high = pricing[1];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto p=q.front();
                    q.pop();
                if(grid[p.first][p.second]==0)
                    continue;
                int a = grid[p.first][p.second];
                grid[p.first][p.second]=0;
                if(a!=1){
                    if(a>=low && a<=high){
                        pq.push({dist,a,p.first,p.second});
                        if(pq.size()>k) pq.pop();
                    }
                }
                for(int i = 0;i<4;i++){
                    int row=p.first+drow[i],col=dcol[i]+p.second;
                    if(row>=0 && row<n && col>=0 && col<m)
                        q.push({row,col});
                }      
            }
            dist++;
        }
        vector<vector<int>> ans;
        while(k>0 && pq.size()>0){
            ans.push_back({pq.top()[2],pq.top()[3]});
            pq.pop();
            k--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};