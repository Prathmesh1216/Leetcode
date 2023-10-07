class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[2]==b[2] && a[1]==b[1]) return a[0]>b[0];
        if(a[2]==b[2]) return a[1]>b[1];
        return a[2]>b[2];
    }
    int dp[101][101];
    int solve(int i,int li,vector<vector<int>>& cuboids){
        if(i==cuboids.size()) return 0;
        if(dp[i][li+1]!=-1) return dp[i][li+1];
        if(li==-1){
            return dp[i][li+1] = max(cuboids[i][2] + solve(i+1,i,cuboids),solve(i+1,li,cuboids));
        }
        int ans = solve(i+1,li,cuboids);
        if(cuboids[i][0]<=cuboids[li][0] && cuboids[i][1]<=cuboids[li][1] && cuboids[i][2]<=cuboids[li][2]) ans = max(ans,cuboids[i][2]+solve(i+1,i,cuboids));
        return dp[i][li+1] = ans;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        memset(dp,-1,sizeof(dp));
        for(auto& it : cuboids){
            sort(it.begin(),it.end());
        }
        sort(cuboids.begin(),cuboids.end(),cmp);
        return solve(0,-1,cuboids);
    }
};