class Solution {
public:
    vector<int> ps; 
    int dp[1001][1001];
    int solve(int i,int j,bool turn,vector<int>& nums){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(!turn) return dp[i][j] = max(ps[j]-ps[i]+solve(i+1,j,1,nums),ps[j-1]-ps[i]+nums[i]+solve(i,j-1,1,nums));
        return dp[i][j] = min(-(ps[j]-ps[i])+solve(i+1,j,0,nums),-(ps[j-1]-ps[i]+nums[i])+solve(i,j-1,0,nums));
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        memset(dp,-1,sizeof(dp));
        ps.resize(n);
        ps[0] = stones[0];
        for(int i = 1;i<n;i++) ps[i] += ps[i-1] + stones[i];
        return solve(0,n-1,0,stones);
    }
};