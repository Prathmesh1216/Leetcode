class Solution {
public:
    int dp[10][2][(1<<10)][2];
    int solve(int i,bool restricted,int mask,bool rep,string& s){
        if(i==s.length()) return rep?1:0;
        auto& res = dp[i][restricted][mask][rep];
        if(res!=-1) return res;
        if(restricted){
            int ans = 0;
            for(int j = 0;j<=(s[i]-'0');j++){
                if(mask==0 && j==0) ans += solve(i+1,j==(s[i]-'0'),mask,rep,s);
                else ans += solve(i+1,j==(s[i]-'0'),mask|(1<<j),rep | (mask&(1<<j)),s);
            }
            return res = ans;
        }
        int ans = 0;

        for(int j = 0;j<=9;j++){
            if(mask==0 && j==0) ans += solve(i+1,0,mask,rep,s);
            else ans += solve(i+1,0,mask|(1<<j),rep | (mask&(1<<j)),s);
        }
     
        return res = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,0,s);
    }
};