class Solution {
public:
    int n;
    int a = 0;
    int dp[41][1025];
    int m = 1e9+7;
    int solve(int i,int mask,vector<int>& vhats){
        if(i==41) return mask==a;
        if(dp[i][mask]!=-1) return dp[i][mask];
        long long ans = solve(i+1,mask,vhats)%m;
        if(vhats[i]){
            for(int j = 0;j<n;j++){
                if(vhats[i]&(1<<j) && !(mask&(1<<j))) ans = (ans + solve(i+1,mask|(1<<j),vhats))%m;
            }
        }
        return dp[i][mask] = ans%m;
    }
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        vector<int> vhats(41);
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<hats.size();i++){
            for(int j = 0;j<hats[i].size();j++){
                vhats[hats[i][j]] |= (1<<i);
            }
        }
        for(int i = 0;i<n;i++){
            a |= (1<<i);
        }
        return solve(1,0,vhats);
    }
};