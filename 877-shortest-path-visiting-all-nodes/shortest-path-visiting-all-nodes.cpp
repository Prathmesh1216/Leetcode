class Solution {
public:
    int n;
    int dp[12][80][2<<12];
    int solve(int node,int cnt,int mask,vector<vector<int>>& graph){
        if(cnt>(n*(n+1)/2)) return 123456789;
        bool flag = true;
        for(int i = 0;i<n;i++){
            if((mask&(1<<i))==0) {flag = false;break;}
        }
        if(flag) return -1;
        if(dp[node][cnt][mask]!=-1) return dp[node][cnt][mask];
        int ans = 123456789;
        for(auto& it : graph[node]){
            ans = min(ans,1 + solve(it,cnt + 1,mask|(1<<node),graph));
        }
        return dp[node][cnt][mask] = ans;

    }
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        if(n==0) return 0;
     memset(dp,-1,sizeof(dp));
        int ans = 123456789;
        for(int i = 0;i<n;i++){
            ans = min(ans,solve(i,0,0,graph));
        }
        if(ans>=123456789) return 0;
        return ans;

    }
};