class Solution {
public:
    int dp[10][1024][2];
    int solve(int i,int mask,bool restricted,string& s){
        if(i==s.length()) return mask!=0;
        if(dp[i][mask][restricted]!=-1) return dp[i][mask][restricted];
        if(restricted){
            int ans = 0;
            for(int j = 0;j<=(s[i]-'0');j++){
                if(mask&(1<<j)) continue;
                if(mask==0 && j==0) {ans += solve(i+1,mask,!restricted,s);continue;}
                if(j==s[i]-'0') ans += solve(i+1,mask|(1<<j),restricted,s);
                else ans += solve(i+1,mask|(1<<j),!restricted,s);        
            }
            return dp[i][mask][restricted] = ans;
        }
        int ans = 0;
        for(int j = 0;j<=9;j++){
            if(mask&(1<<j)) continue;
            if(mask==0 && j==0) {ans += solve(i+1,mask,restricted,s);continue;}
            ans += solve(i+1,mask|(1<<j),restricted,s);
        }
        return dp[i][mask][restricted] = ans;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,1,s);
    }
};