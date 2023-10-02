class Solution {
public:
    // 0->office,1->hotel
    int n;
    long long dp[100001][4][3];
    long long solve(int i,int se,int last,string& s){
        if(se==3) return 1;
        if(i==n){
            return 0;
        }
        if(dp[i][se][last+1]!=-1) return dp[i][se][last+1];
        if(last==-1) return dp[i][se][last+1] = solve(i+1,se+1,s[i]-'0',s) + solve(i+1,se,last,s);
        if(last==0){
            if(s[i]=='0') return dp[i][se][last+1] = solve(i+1,se,last,s);
            else return dp[i][se][last+1] = solve(i+1,se,last,s) + solve(i+1,se+1,s[i]-'0',s);
        }
        if(last==1){
            if(s[i]=='1') return dp[i][se][last+1] = solve(i+1,se,last,s);
            else return dp[i][se][last+1] = solve(i+1,se,last,s) + solve(i+1,se+1,s[i]-'0',s);
        }
        return 0;
    }
    long long numberOfWays(string s) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1,s);
    }
};