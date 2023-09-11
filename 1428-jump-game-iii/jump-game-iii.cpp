class Solution {
public:
    int n;
    // int dp[50001];
    // int solve(int i,vector<int>& arr){
    //     if(i<0 || i>=n) return 0;
    //     if(arr[i]==0) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     return solve(i+arr[i],arr) || solve(i-arr[i],arr);
    // }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        queue<int> q;
        vector<int> adj[n];
        for(int i = 0;i<n;i++){
            if(i+arr[i]<n){
                adj[i].push_back(i+arr[i]);
            }
            if(i-arr[i]>=0) adj[i].push_back(i-arr[i]);
        }
        q.push(start);
        vector<bool> vis(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(arr[node]==0) return true;
            vis[node] = 1;
            for(auto it : adj[node]){
                if(!vis[it]) q.push(it);
            }
        }
        return false;
    }
};