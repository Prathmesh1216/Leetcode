class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& q, vector<int>& king) {
        vector<vector<int>> ans;
        int n = 8,m = 8;
        vector<vector<int>> queens(n,vector<int>(m,0));
        for(auto& it : q) queens[it[0]][it[1]] = 1;
        int r = king[0],c = king[1];
        while(r<n){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            r++;
        }
        r = king[0],c = king[1];
        while(c<m){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            c++;
        }
        r = king[0],c = king[1];
        while(r>=0){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            r--;
        }
        r = king[0],c = king[1];
        while(c>=0){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            c--;
        }
        r = king[0],c = king[1];
        while(r<n && c<m){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            r++;
            c++;
        }
        r = king[0],c = king[1];
        while(r>=0 && c<m){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            r--;
            c++;
        }
        r = king[0],c = king[1];
        while(r>=0 && c>=0){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            r--;
            c--;
        }
        r = king[0],c = king[1];
        while(r<n && c>=0){
            if(queens[r][c]==1){
                ans.push_back({r,c});
                break;
            }
            r++;
            c--;
        }
        return ans;
    }
};