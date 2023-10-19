class Solution {
public:
    int dp[100001][2];
    int solve(int i,vector<int>& prices,bool b){
        if(i==prices.size()) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        if(b) return dp[i][b] = max(solve(i+1,prices,b),-prices[i]+solve(i+1,prices,!b));
        return dp[i][b] = max(prices[i]+solve(i,prices,!b),solve(i+1,prices,b));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,1);
    }
};