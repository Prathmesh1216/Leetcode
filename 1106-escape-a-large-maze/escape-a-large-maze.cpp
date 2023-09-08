class Solution {
public:
    map<pair<int,int>,int> block;
    bool bfs(int r,int c,int trow,int tcol){
        set<pair<int,int>> st;
        queue<pair<pair<int,int>,int>> q;
        q.push({{r,c},0});
        st.insert({r,c});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int d = it.second;
            if(d>200) return true;
            if(row==trow && col==tcol) return true;
            for(int i = 0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr>=0 && nr<1e6 && nc>=0 && nc<1e6 && st.find({nr,nc})==st.end() && block.find({nr,nc})==block.end()){
                    st.insert({nr,nc});
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto it : blocked){
            block[{it[0],it[1]}]++;
        }
        if(bfs(source[0],source[1],target[0],target[1]) && bfs(target[0],target[1],source[0],source[1])) return true;
        return false;
    }
};