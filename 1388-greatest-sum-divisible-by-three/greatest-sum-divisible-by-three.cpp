class Solution {
public:
    int dp[40001][4];
    int solve(int i,int sum,vector<int>& nums){
        if(i==nums.size()){
            if(sum==0) return 0;
            return -123456789;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = max(solve(i+1,sum,nums),nums[i]+ solve(i+1,(sum+nums[i])%3,nums));
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums);
    }
};