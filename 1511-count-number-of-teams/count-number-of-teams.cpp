class Solution {
public:
    int n;
    int dp[1001][1001][4][3];
    int solve(int i,int li,int c,int inc,vector<int>& rating){
        if(c==3) return 1;
        if(i==n) return 0;
        if(dp[i][li+1][c][inc]!=-1) return dp[i][li+1][c][inc];
        if(inc==0) return dp[i][li+1][c][inc] = solve(i+1,li,c,inc,rating) + solve(i+1,i,c+1,1,rating) + solve(i+1,i,c+1,2,rating);
        if(inc==1){
            if(rating[i]>rating[li]) return dp[i][li+1][c][inc] = solve(i+1,i,c+1,inc,rating) + solve(i+1,li,c,inc,rating);
            return dp[i][li+1][c][inc] = solve(i+1,li,c,inc,rating);
        }
        if(rating[i]<rating[li]) return dp[i][li+1][c][inc] = solve(i+1,i,c+1,inc,rating) + solve(i+1,li,c,inc,rating);
        return dp[i][li+1][c][inc] = solve(i+1,li,c,inc,rating);
    }
    int numTeams(vector<int>& rating) {
        n = rating.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,0,0,rating);
    }
};