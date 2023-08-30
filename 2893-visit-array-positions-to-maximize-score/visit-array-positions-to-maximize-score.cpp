class Solution {
public:
    int n;
    long long dp[100001][2];
    long long solve(int i,bool parity,vector<int>& nums,int x){
        if(i==n) return 0;
        if(dp[i][parity]!=-1) return dp[i][parity];
        bool par = nums[i]&1;
        if(par==parity){
            return dp[i][parity] = nums[i] + solve(i+1,parity,nums,x);
        }
        return dp[i][parity] = max(nums[i]-x+solve(i+1,par,nums,x),solve(i+1,parity,nums,x));
    }
    long long maxScore(vector<int>& nums, int x) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return (1LL*nums[0] + solve(1,nums[0]&1,nums,x));
    }
};