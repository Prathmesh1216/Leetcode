class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    int ub(int i,vector<vector<int>>& offers){
        int start = i+1;
        int end = offers.size()-1;
        int ans = offers.size();
        while(start<=end){
            int mid = start + (end-start)/2;
            if(offers[mid][0]>offers[i][1]){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
    int dp[100001];
    int solve(int i,vector<vector<int>>& offers){
        if(i==offers.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int p1 = 0;
        int p2 = 0;
        p1 = offers[i][2] + solve(ub(i,offers),offers);
        p2 = solve(i+1,offers);
        return dp[i] = max(p1,p2);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end(),cmp);
        memset(dp,-1,sizeof(dp));
        return solve(0,offers);
    }
};