class Solution {
public:
    int dp[1001];
    int solve(int W,vector<int>& nums){
        if(W==0) return 1;
        if(W<0) return 0;
        int cnt = 0;
        if(dp[W]!=-1) return dp[W];
        for(int i = 0;i<nums.size();i++){
            cnt += solve(W-nums[i],nums);
        }
        return dp[W] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(target,nums);
    }
};