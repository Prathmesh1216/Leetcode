class Solution {
public:
    int n;
    int mod = 1e9+7;
    int dp[101][201];
    int solve(int i,int finish,vector<int>& locations,int fuel){
        if(fuel<0) return 0;
        if(dp[i][fuel]!=-1) return dp[i][fuel];
        if(fuel==0){
            if(i==finish) return  dp[i][fuel] =1;
            return dp[i][fuel] = 0;
        }
        long long ans = 0;
        if(i == finish) ans = 1;
        for(int j = 0;j<n;j++){
            if(i!=j ) ans += solve(j,finish,locations,fuel-abs(locations[i]-locations[j]));
        }
        return dp[i][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(start,finish,locations,fuel);
    }
};