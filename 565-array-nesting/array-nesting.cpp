class Solution {
public:
    int ans = -1;
    void dfs(int node,vector<int>& edges,vector<int>& vis,vector<int>& dfsvis,vector<int>& count){
        if(node ==-1) return;
        vis[node] = 1;
        dfsvis[node] = 1;
        int child = edges[node];
        if(child!=-1 && !vis[child]){
            count[child] = count[node] + 1;
            dfs(child,edges,vis,dfsvis,count);
        }
        else if(child!=-1 && dfsvis[child]){
            ans = max(ans,count[node]-count[child]+1);
        }
        dfsvis[node] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        vector<int> count(n,1);
        for(int i = 0;i<n;i++){
            if(!vis[i]) dfs(i,edges,vis,dfsvis,count);
        }
        return ans;
    }
    int arrayNesting(vector<int>& nums) {
       // n = nums.size();
        return longestCycle(nums);
        
        
    }
};
