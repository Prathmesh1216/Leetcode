class Solution {
public:
    int dp[501][501];
    int solve(int l,int r,vector<int>& ps,vector<int>& stoneValue){
        if(l==r) return 0;
        int fans = 0;
        if(dp[l][r]!=-1) return dp[l][r];
        for(int k = l;k<r;k++){
            int ans = 0;
            int left = ps[k]-ps[l] + stoneValue[l];
            int right = ps[r] - ps[k];
            if(left==right) ans = left + max(solve(l,k,ps,stoneValue),solve(k+1,r,ps,stoneValue));
            else if(left<right) ans  = left + solve(l,k,ps,stoneValue);
            else ans = right + solve(k+1,r,ps,stoneValue);
            fans = max(ans,fans);
        }
        return dp[l][r] = fans;
    }
    int stoneGameV(vector<int>& stoneValue) {
     int n = stoneValue.size();
     vector<int> ps(n);
     memset(dp,-1,sizeof(dp));
     ps[0] = stoneValue[0];
     for(int i = 1;i<n;i++){
         ps[i] = ps[i-1] + stoneValue[i];
     }   
     return solve(0,n-1,ps,stoneValue);
    }
};