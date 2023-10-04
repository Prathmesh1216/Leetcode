class Solution {
public:
    vector<int> ps;
    int n;
    double solve(int i,int k,vector<int>& nums,vector<vector<double>>& dp){
        if(i>=n) return -123456789;
        if(k==1) return (1.0*(ps[n-1]-ps[i]+nums[i]))/(n-i);
        if(dp[i][k]!=-1) return dp[i][k];
        double ans = 0;
        for(int d = i;d<=(n-k);d++){
            ans = max(ans,(1.0*(ps[d]-ps[i]+nums[i]))/(d-i+1) + solve(d+1,k-1,nums,dp));
        }
        return dp[i][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
       vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        ps.resize(n);
        ps[0] = nums[0];
        for(int i = 1;i<n;i++){
            ps[i] = nums[i] + ps[i-1];
        }   
        return solve(0,k,nums,dp);
    }
};