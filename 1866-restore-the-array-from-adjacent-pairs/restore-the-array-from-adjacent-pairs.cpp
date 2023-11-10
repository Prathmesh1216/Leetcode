class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size()+1;
        vector<int> adj[n];
        map<int,int> mp;
        int i = 0;
        int start = -1;
        vector<int> indegree(n);
        for(auto it : adjacentPairs){
            if(mp.find(it[0])==mp.end()){
                mp[it[0]] = i;
                i++;
            }
            if(mp.find(it[1])==mp.end()){
                mp[it[1]] = i;
                i++;
            }
            int u = mp[it[0]];
            int v = mp[it[1]];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        for(int i = 0;i<n;i++){
            if(indegree[i]==1){
                start = i;
                break;
            }
        }
        unordered_map<int,int> mp1;
        for(auto it : mp){
            mp1[it.second] = it.first;
        }
        vector<int> ans;
        vector<bool> vis(n);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(mp1[node]);
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        return ans;
    }
};