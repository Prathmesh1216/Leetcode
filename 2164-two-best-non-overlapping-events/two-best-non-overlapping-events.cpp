class Solution {
public:
    int n;
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
        if(i==n-1) return events[i][2];
        if(dp[i][k]!=-1) return dp[i][k];
        int ans = solve(i+1,k,events,dp);
        int ans2 = 0;
        int j = ub(i+1,events[i][1],events);
        ans = max(ans,events[i][2]+solve(j,k-1,events,dp));
        return dp[i][k] = ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        vector<vector<int>> dp(n+1,vector<int>(2+1,-1));
        sort(events.begin(),events.end());
        return solve(0,2,events,dp);
    }
};