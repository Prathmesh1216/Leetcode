class Solution {
public:
    int dp[10001][101];
    int solve(int f,int e){
        if(e==0 || f==0) return 0;
        if(e==1) return f;
        if(f==1) return 1;
        if(dp[f][e]!=-1) return dp[f][e];
        int ans = 123456789;
        int start = 1;
        int end = f;
        while(start<=end){
            int mid = start + (end-start)/2;
            int left = solve(mid-1,e-1);
            int right = solve(f-mid,e);
            int temp = 1 + max(left,right);
            if(left<right) start = mid + 1;
            else end = mid - 1;
            ans = min(ans,temp);
        }
        return dp[f][e] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};