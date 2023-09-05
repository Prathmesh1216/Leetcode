class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int sum,vector<int>& rods){
        if(i==n){
            if(sum==5000) return 0;
            return INT_MIN;
        }
        if(dp[i][sum]!=INT_MIN) return dp[i][sum];
        return dp[i][sum] = max({solve(i+1,sum,rods),rods[i]+solve(i+1,sum+rods[i],rods),solve(i+1,sum-rods[i],rods)});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        dp.resize(n+1,vector<int>(10001,INT_MIN));
        int ans = solve(0,5000,rods);\
        return (ans<=0)?0:ans;
    }
};