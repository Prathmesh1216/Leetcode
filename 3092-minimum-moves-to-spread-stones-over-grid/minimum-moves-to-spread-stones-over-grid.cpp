class Solution {
public:
    int solve(int i,vector<vector<int>>& garib,vector<vector<int>>& v){
        if(i==garib.size()) return 0;
        int ans = 123456789;
        for(int j = 0;j<v.size();j++){
            if(v[j][2]>0){
                v[j][2]--;
                ans = min(ans,abs(garib[i][0]-v[j][0]) + abs(garib[i][1]-v[j][1])+solve(i+1,garib,v));
                v[j][2]++;
            }
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        ios_base:: sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> v;
        vector<vector<int>> garib;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(grid[i][j]>1) v.push_back({i,j,grid[i][j]-1});
                if(grid[i][j]==0) garib.push_back({i,j});
            }
        }
       // cout << garib.size() << " " << v.size() << endl;
        return solve(0,garib,v);


    }
};