class Solution {
public:
    int dp[100];
    int solve(int i,vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(solve(i+1,nums),nums[i]+solve(i+2,nums));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};