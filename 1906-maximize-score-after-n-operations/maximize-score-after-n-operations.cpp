class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int mask,vector<int>& nums){
        if(i==n) return 0;
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans = 0;
        for(int j = 0;j<nums.size();j++){
            for(int k = 0;k<nums.size();k++){
                if(j!=k && !(mask&(1<<j)) && !(mask&(1<<k))) ans = max(ans,(i+1)*gcd(nums[j],nums[k]) + solve(i+1,(mask|(1<<j))|(1<<k),nums));
            }
        }
        return dp[i][mask] = ans;
    }
    int maxScore(vector<int>& nums) {
        n = nums.size()/2;
        dp.resize(n+1,vector<int>(1<<(2*n),-1));
        return solve(0,0,nums);
    }
};