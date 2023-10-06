class Solution {
public:
    int n;
    vector<int> len;
    void dfs(int node,vector<int>& edges,vector<int>& vis,vector<int>& dfsvis,int& ans){
        vis[node] = 1;
        dfsvis[node] = 1;
        len[node]++;
        if(edges[node]!=-1){
            if(!vis[edges[node]]){
                len[edges[node]] += len[node];
                dfs(edges[node],edges,vis,dfsvis,ans);
            }
            else if(dfsvis[edges[node]]){
                ans = max(ans,len[node]-len[edges[node]]+1);
            }
        }
        dfsvis[node] = 0;
        return;
    }
    int longestCycle(vector<int>& edges) {
        n = edges.size();
        len.resize(n);
        int ans = -1;
        vector<int> vis(n),dfsvis(n);
        for(int i = 0;i<n;i++){
            if(!vis[i]) dfs(i,edges,vis,dfsvis,ans);
        }
        return ans;

    }
};