class Solution {
public:
    int n,m;
    int dp[26][64][64][7][7] = {};
    int solve(int i,int im,int em,int ic,int ec){
        if(ic==0 && ec==0) return 0;
        int r = i/m,c = i%m;
        if(r>=n) return 0;
         if(dp[i][im][em][ic][ec]) return dp[i][im][em][ic][ec];
        int ans2 = 0,ans3 = 0;
        int nim = (im<<1)&63; int nem = (em<<1)&63;
        int ans1 = solve(i+1,nim,nem,ic,ec);
        if(ic){
            ans2 = 120;
            int cnt = 0;
            if(c>0 && im&1) ans2 -= 30,cnt++;
            if(c>0 && em&1) ans2 += 20,cnt++;
            if(r>0 && im&(1<<(m-1))) ans2 -= 30,cnt++;
            if(r>0 && em&(1<<(m-1))) ans2 += 20,cnt++;
            ans2 -= 30*cnt;
            ans2 += solve(i+1,nim+1,nem,ic-1,ec);
        }
        if(ec){
            ans3 = 40;
            int cnt = 0;
            if(c>0 && im&1) ans3 -= 30,cnt++;
            if(c>0 && em&1) ans3 += 20,cnt++;
            if(r>0 && im&(1<<(m-1))) ans3 -= 30,cnt++;
            if(r>0 && em&(1<<(m-1))) ans3 += 20,cnt++;
            ans3 += 20*cnt;
            ans3 += solve(i+1,nim,nem+1,ic,ec-1);           
        }
        return dp[i][im][em][ic][ec] = max({ans1,ans2,ans3});
    }
    int getMaxGridHappiness(int N, int M, int ic, int ec) {
        n = N,m = M;
      //  memset(dp,-123456789,sizeof(dp));
        return solve(0,0,0,ic,ec);
    }
};