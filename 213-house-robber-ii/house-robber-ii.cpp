class Solution {
public:
    int dp[101];
    int solve(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(solve(i+1,j,nums),nums[i] + solve(i+2,j,nums));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int ans1 = solve(0,nums.size()-2,nums);
        memset(dp,-1,sizeof(dp));
        int ans2 = solve(1,nums.size()-1,nums);
        return max(ans1,ans2);
    }
};