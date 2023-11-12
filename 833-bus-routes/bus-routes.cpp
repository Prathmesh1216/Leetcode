class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int,vector<int>> g;
        for(int i = 0;i<routes.size();i++){
            int n = routes[i].size();
            for(int j = 0;j<n;j++){
                g[routes[i][j]].push_back(i);
            }
        }
        queue<int> q;
        set<int> vis;
        for(auto& it : g[source]) q.push(it),vis.insert(it);
        int ans = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int currbus = q.front();
                q.pop();
                for(auto& it : routes[currbus]){
                    if(it==target) return ans;
                    for(auto& iit: g[it]){
                        if(!vis.count(iit)){
                            vis.insert(iit);
                            q.push(iit);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};