class Solution {
public:
   // void dfs()
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
            vector<vector<int>> g(n+1);
            vector<int> indegree(n+1);
            vector<int> ans(n+1);
            for(auto& it : relations){
                g[it[0]].push_back(it[1]);
                indegree[it[1]]++;
            }
            queue<int> q;
            for(int i = 1;i<=n;i++){
                if(indegree[i]==0) q.push(i),ans[i] = time[i-1];
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto& it : g[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                    ans[it] = max(ans[it],ans[node]+time[it-1]);
                }
            }
         int fans = 0;
         for(int i = 1;i<=n;i++) fans = max(fans,ans[i]);
         return fans;   
    }
};