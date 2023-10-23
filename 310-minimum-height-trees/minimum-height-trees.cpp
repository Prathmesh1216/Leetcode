class Solution {
public:
    vector<vector<int>> g;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return {};
        if(n==1) return {0};
        if(n==2) return {0,1};
        vector<int> indegree(n);
        g.resize(n);
        for(auto& it : edges) g[it[0]].push_back(it[1]),g[it[1]].push_back(it[0]),indegree[it[0]]++,indegree[it[1]]++;
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i]==1) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            int a = q.size();
            while(a--){
                int node = q.front();q.pop();
                ans.push_back(node);
                for(auto& it : g[node]){
                    indegree[it]--;
                    if(indegree[it]==1) q.push(it);
                }
            }
        }
        return ans;

    }
};