class Solution {
public:
    int n;
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    int ub(int i,int val,vector<vector<int>>& events){
        int start = i;
        int end = n-1;
        int ans = n;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(events[mid][0]>val){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    int solve(int i,int k,vector<vector<int>>& events,vector<vector<int>>& dp){
        if(i==n || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans = solve(i+1,k,events,dp);
        int ans2 = 0;
        int j = ub(i+1,events[i][1],events);
        ans = max(ans,events[i][2]+solve(j,k-1,events,dp));
        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end(),cmp);
        return solve(0,k,events,dp);
    }
};