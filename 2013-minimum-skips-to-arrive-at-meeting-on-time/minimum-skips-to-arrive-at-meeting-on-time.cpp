class Solution {
public:
    int n;
    int speed;
    int dp[1001][1001];
    long long solve(int i,int mid,vector<int>& dist){
        if(i>=n) return 0;
        if(dp[i][mid]!=-1) return dp[i][mid];
        long long ans = solve(i+1,mid,dist) + dist[i];
        if(ans%speed) ans = ((ans/speed)+1)*speed;
        if(mid>0) ans = min(ans,solve(i+1,mid-1,dist)+ dist[i]);
        return dp[i][mid] = ans;
    }
    int minSkips(vector<int>& dist, int s, int hoursBefore) {
        n = dist.size();
        speed = s;
        memset(dp,-1,sizeof(dp));
        int start = 0;
        int end = n-1;
        int ans = -1;
        long long target = hoursBefore*1LL*speed;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(solve(0,mid,dist)<=target){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};