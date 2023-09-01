class Solution {
public:
    int n,m;
    int mod  = 1e9+7;
    vector<vector<int>> count;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,int k){
        if(count[i][j]==0) return 0;
        if(k==1) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long ans = 0;
        for(int ni = i+1;ni<n;ni++){
            if(count[i][j]-count[ni][j]>0)ans += solve(ni,j,k-1);
        }
        for(int nj = j+1;nj<m;nj++){
            if(count[i][j]-count[i][nj])ans += solve(i,nj,k-1);
        }
        return dp[i][j][k] = ans%mod;

    }
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        count.resize(n+1,vector<int>(m+1,0));
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                count[i][j] = count[i+1][j]+ count[i][j+1]-count[i+1][j+1] + (pizza[i][j]=='A');
            }
        }
        return solve(0,0,k);
    }
};