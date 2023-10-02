class Solution {
public:
    #define pb push_back
    int dp[100001];
    int solve(int node,vector<vector<int>>& g){
        if(dp[node]!=-1) return dp[node];
        int ans = 1;
        for(auto& it : g[node]){
            ans += solve(it,g);
        }
        return dp[node] = ans;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> g(n);
        for(int i = 0;i<n;i++){
            if(parents[i]!=-1) g[parents[i]].pb(i);
        }
       
        long long maxi = 0;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            long long sc = 1;
            int sz = 0;
            for(auto& it : g[i]){
                long long cs = solve(it,g);
                if(cs) sc *= cs,sz+=cs;
            }
            if(n-1-sz>0) sc *= (n-1-sz);
            if(sc>maxi){
                maxi = sc;
                cnt = 1;
            }
            else if(sc==maxi){
                cnt++;
            }
        }
     //   for(int i = 0;i<n;i++) cout << dp[i] << endl;
        return cnt;

    }
};