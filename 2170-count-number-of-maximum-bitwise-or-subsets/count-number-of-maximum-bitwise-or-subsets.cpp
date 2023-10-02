class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int cs,int t,vector<int>& nums,int n){
        if(i==n){
            if(cs==t) return 1;
            return 0;
        }
        if(dp[i][cs]!=-1) return dp[i][cs];
        return dp[i][cs] = solve(i+1,cs|nums[i],t,nums,n) + solve(i+1,cs,t,nums,n);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int t = 0;
        for(auto& it : nums) t|=it;
        int n = nums.size();
        dp.resize(n+1,vector<int>(t+1,-1));
        return solve(0,0,t,nums,n);
    }
};