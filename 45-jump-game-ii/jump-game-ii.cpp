class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,123456789);
        dp[0] = 0;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<=nums[i] && i+j<n;j++){
                dp[i+j] = min(dp[i+j],1+dp[i]);
            }
        }
        return dp[n-1];
    }
};