class Solution {
public:
    int l;
    long long dp[201][201];
    long long solve(int m,int n,map<pair<int,int>,int>& mp){
        long long ans = mp[{m,n}];
        if(dp[m][n]!=-1) return dp[m][n];
        for(int i = 1;i<=m/2;i++){
            ans = max(ans,solve(m-i,n,mp)+solve(i,n,mp));
        }
        for(int j = 1;j<=n/2;j++){
            ans = max(ans,solve(m,j,mp)+solve(m,n-j,mp));
        }
        return dp[m][n] =  ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        l = prices.size();
        map<pair<int,int>,int> mp;
        memset(dp,-1,sizeof(dp));
        for(auto it : prices){
            mp[{it[0],it[1]}] = it[2];
        }
        return solve(m,n,mp);
  

    }
};