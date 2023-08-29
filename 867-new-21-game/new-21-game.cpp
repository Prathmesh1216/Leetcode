class Solution {
public:
    // int solve(int points,int k,int mps,int n){
    //     if(points>=k){
    //         if(points<=n) return 1;
    //         return 0;
    //     }
    //     int ans = 0;
    //     for(int i = 1;i<=mps;i++){
    //         ans += solve(points+i,k,mps,n);
    //     }
    //     return ans;
    // }
    double new21Game(int n, int k, int mps) {
        vector<double> dp(n+1,0);
        if(n==0 || k==0) return 1;
        dp[0] = 1;
        double probsum = (k==0)? 0:1;

        for(int i = 1;i<=n;i++){
            dp[i] = probsum/mps;
            if(i<k) probsum += dp[i];
            if(i-mps>=0 && i-mps<k){
                probsum -= dp[i-mps];
            }
        }
        double ans = 0;
        for(int i = k;i<=n;i++){
            ans += dp[i];
        }
        return ans;
    }
};