class Solution {
public:
    int lb(int s,int val,vector<vector<int>>& rides){
        int start = s;
        int end = rides.size()-1;
        int ans = end+1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(rides[mid][0]>=val){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    long long dp[100001];
    long long solve(int i,vector<vector<int>>& rides){
        if(i>=rides.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans1 = solve(i+1,rides);
        int j = lb(i+1,rides[i][1],rides);
        long long ans2 = rides[i][1] - rides[i][0] + rides[i][2] + solve(j,rides);
        return dp[i] = max(ans1,ans2);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,rides);
    }
};