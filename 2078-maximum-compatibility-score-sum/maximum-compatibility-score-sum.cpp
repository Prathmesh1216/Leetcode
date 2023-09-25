class Solution {
public:
    int dp[9][(1<<9)];
    int solve(int i,int mask,int m,vector<vector<int>>& comp){
        if(i==m) return 0;
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans  = 0;
        for(int j = 0;j<m;j++){
            if(!(mask&(1<<j))) ans = max(ans,comp[i][j] + solve(i+1,mask|(1<<j),m,comp));
        }
        return dp[i][mask] = ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> comp(m,vector<int>(m,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<n;k++){
                    if(students[i][k]==mentors[j][k]) comp[i][j]++;
                }
            }
        }
        return solve(0,0,m,comp);
    }
};