class Solution {
public:
    int dp[101][21][101];
    int solve(int i,int lc,int nh,vector<int>& houses,vector<vector<int>>& cost,int m,int n,int target){
        if(nh>target) return 123456789;
        if(i==m){
            if(nh==target) return 0;
            return 123456789;
        }
        if(dp[i][lc][nh]!=-1) return dp[i][lc][nh];
        int ans = 123456789;
        if(i==0){
            if(houses[i]==0){
                for(int j = 0;j<n;j++){
               ans = min(cost[i][j]+solve(i+1,j+1,nh+1,houses,cost,m,n,target),ans);
                }
                return dp[i][lc][nh] = ans;
            }
            return dp[i][lc][nh] = solve(i+1,houses[i],1,houses,cost,m,n,target);
        }

        if(houses[i]==0){
            for(int j = 0;j<n;j++){
                if(j+1!=lc) ans = min(cost[i][j]+solve(i+1,j+1,nh+1,houses,cost,m,n,target),ans);
                else ans = min(ans,cost[i][j]+solve(i+1,lc,nh,houses,cost,m,n,target));
            }
            return dp[i][lc][nh] = ans;
        }
        if(houses[i]==lc) return dp[i][lc][nh] = solve(i+1,lc,nh,houses,cost,m,n,target);
        return dp[i][lc][nh] = solve(i+1,houses[i],nh+1,houses,cost,m,n,target);
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,houses,cost,m,n,target);
        if(ans>=123456789) return -1;
        return ans;
    }
};