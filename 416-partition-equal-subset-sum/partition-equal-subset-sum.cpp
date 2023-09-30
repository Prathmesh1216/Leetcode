class Solution {
public:
    int n;
    int dp[201][10001];
    int solve(int i,vector<int>& nums,int t){
        if(t<0) return false;
        if(t==0) return true;
        if(i==n) return false;
        if(dp[i][t]!=-1) return dp[i][t];
        return dp[i][t] = solve(i+1,nums,t) || solve(i+1,nums,t-nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        return solve(0,nums,sum/2);
    }
};