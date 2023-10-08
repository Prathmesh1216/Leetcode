class Solution {
public:
    int numOfMinutes(int n, int hid, vector<int>& manager, vector<int>& ift) {
        vector<vector<int>> g(n);
        for(int i = 0;i<manager.size();i++){
            if(manager[i]!=-1) g[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        int ans = 0;
        q.push({hid,0});
        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            if(g[node].size()==0){
                ans = max(ans,time); continue;
            }
            for(auto& it : g[node]){
                q.push({it,time+ift[node]});
            }
        }
        return ans;
    }
};