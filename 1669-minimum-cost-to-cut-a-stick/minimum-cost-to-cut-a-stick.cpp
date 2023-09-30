class Solution {
public:
    int dp[102][102];
    int solve(int i,int j,vector<int>& cuts){
        if(j<i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 123456789;
        for(int k = i;k<=j;k++){
            ans = min(ans,cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts)+solve(k+1,j,cuts));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(1,m,cuts);
    }
};