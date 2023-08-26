class Solution {
public:
    int dp[1001][1001];
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int solve(int i,int li,vector<vector<int>>& pairs){
        if(i==pairs.size()) return 0;
        if(dp[i][li+1]!=-1) return dp[i][li+1];
        if(li==-1) return dp[i][li+1] = max(1 + solve(i+1,i,pairs),solve(i+1,li,pairs));
        if(pairs[i][0] > pairs[li][1]) return dp[i][li+1] = max(1 + solve(i+1,i,pairs),solve(i+1,li,pairs));
        else return dp[i][li+1] = solve(i+1,li,pairs);  
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end(),cmp);
        return solve(0,-1,pairs);

    }
};