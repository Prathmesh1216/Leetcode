class Solution {
public:
    int n,m;
    long long dp[101][101][102];
    long long solve(int i,int j,int limit,vector<vector<int>>& factory,vector<int>& robot){
        if(j==n) return 0;
        if(i==m) return 1e18;
        if(dp[i][j][limit+1]!=-1) return dp[i][j][limit+1];
        if(limit==-1) return dp[i][j][limit+1] = solve(i,j,factory[i][1],factory,robot);
        if(limit==0) return dp[i][j][limit+1] =  solve(i+1,j,-1,factory,robot);
        long long op1 = 1e18,op2= 1e18;
        op1 = solve(i+1,j,-1,factory,robot);
        if(limit>0) op2 = abs(factory[i][0]-robot[j]) + solve(i,j+1,limit-1,factory,robot);
        return dp[i][j][limit+1] = min(op1,op2);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = robot.size();
        m = factory.size();
        memset(dp,-1,sizeof(dp));
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        return solve(0,0,-1,factory,robot);
    }
};