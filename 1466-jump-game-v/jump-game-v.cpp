class Solution {
public:
    int n ;
    int dp[1001];
    int solve(int i,vector<int>& arr,int d){
        int ans = 1;
        if(dp[i]!=-1) return dp[i];
        int ml = max(i-d,0), mr = min(i+d,n-1);
        for(int j = i-1;j>=ml;j--){
            if(arr[j]<arr[i]) ans = max(ans,1+solve(j,arr,d));
            else break;
        }
        for(int j = i+1;j<=mr;j++){
            if(arr[j]<arr[i]) ans = max(ans,1+solve(j,arr,d));
            else break;
        }
        return dp[i] = ans;

    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memset(dp,-1,sizeof(dp));
        int ans= 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,solve(i,arr,d));
        }
        return ans;
    }
};