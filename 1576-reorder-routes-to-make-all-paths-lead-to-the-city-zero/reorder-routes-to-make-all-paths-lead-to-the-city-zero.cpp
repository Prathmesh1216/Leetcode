class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> g(n);
        for(auto& it : connections){
            g[it[0]].push_back(make_pair(it[1],1));
            g[it[1]].push_back(make_pair(it[0],-1));
        }
        queue<int> q;
        vector<bool> vis(n);
        q.push(0);
        vis[0] = 1;
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();q.pop();
            for(auto& it:g[node]){
                if(!vis[it.first]){
                    q.push(it.first);
                    vis[it.first] = 1;
                    if(it.second==1) cnt++;
                }
            }
        }
        return cnt;
    }
};