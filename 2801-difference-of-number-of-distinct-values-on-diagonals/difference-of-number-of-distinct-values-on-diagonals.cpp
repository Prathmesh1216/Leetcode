class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> tl(n,vector<int>(m,0)),rb(n,vector<int>(m,0)),ans(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            unordered_map<int,int> mp;
            int a = i,b = 0;
            while(a<n && b<m){
                tl[a][b] = mp.size();
                mp[grid[a][b]]++;
                a++;
                b++;
            }
        }
        for(int j = 1;j<m;j++){
            int a = 0,b = j;
            unordered_map<int,int> mp;
            while(a<n && b<m){
                tl[a][b] = mp.size();
                mp[grid[a][b]]++;
                a++;
                b++;
            }
        }
        for(int i = n-1;i>=0;i--){
            int a = i,b = m-1;
            unordered_map<int,int> mp;
            while(a>=0 && b>=0){  
                rb[a][b] = mp.size();
                mp[grid[a][b]]++;
                a--;
                b--;
            }
        }
        for(int j = m-2;j>=0;j--){
            int a = n-1,b = j;
            unordered_map<int,int> mp;
            while(a>=0 && b>=0){
                rb[a][b] = mp.size();
                mp[grid[a][b]]++;
                a--;
                b--;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans[i][j] = abs(tl[i][j]-rb[i][j]);
            }
        }
        return ans;
    }
};