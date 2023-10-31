class Solution {
public:
    int n,m;
    int dp[71][70*70+1];
    int solve(int i,int sum,int target,vector<vector<int>>& mat){
        if(i>=n){
            return abs(target-sum);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans = INT_MAX;
        for(int k = 0;k<m;k++){
            ans = min(ans,solve(i+1,sum+mat[i][k],target,mat));
            if(ans==0){
                return 0;
            }
        }
        return dp[i][sum] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        n = mat.size();
        m = mat[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = INT_MAX;
        return solve(0,0,target,mat);

    }
};