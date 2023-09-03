class Solution {
public:\
    int n,m;
    map<pair<int,int>,int> dp;
    bool isValid(int mid,vector<vector<int>>& dungeon){
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = mid + dungeon[0][0];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i>0 && dp[i-1][j]>0){
                    dp[i][j] = max(dp[i][j],dp[i-1][j] + dungeon[i][j]);
                }
                if(j>0 && dp[i][j-1]>0){
                    dp[i][j] = max(dp[i][j],dp[i][j-1]+ dungeon[i][j]);
                }
            }
        }
        return dp[n-1][m-1]>0;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        int start = 1;
        int end   = (m+n)*1000+1;
        int ans = 1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,dungeon)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};