class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto& it : preq){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);ans.push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};