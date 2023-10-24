class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        for(auto& it : edges){
            g[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0) q.push(i),topo.push_back(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& it : g[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    topo.push_back(it);
                }
            }
        }
        return topo.size()==n;
    }
};