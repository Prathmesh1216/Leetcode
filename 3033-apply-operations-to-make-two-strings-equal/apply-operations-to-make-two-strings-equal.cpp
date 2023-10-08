class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int>& v,int x){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans1= 123456789,ans2 = 123456789,ans3 = 123456789;
        return dp[i][j] = min({v[i+1]-v[i] + solve(i+2,j,v,x),x+solve(i+1,j-1,v,x),v[j]-v[j-1]+solve(i,j-2,v,x)});
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> v;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<s1.length();i++){
            if(s1[i]!=s2[i]) v.push_back(i);
        }
        if(v.size()&1) return -1;
        return solve(0,v.size()-1,v,x);
    }
};