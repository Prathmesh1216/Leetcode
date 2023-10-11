class Solution {
public:
    int n;
    int dp[501][502];
    int solve(int i,int t,vector<int>& nums){
        if(i==n) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        return dp[i][t] = max(solve(i+1,t,nums),t*nums[i] + solve(i+1,t+1,nums));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        memset(dp,-1,sizeof(dp));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,1,satisfaction);
    }
};