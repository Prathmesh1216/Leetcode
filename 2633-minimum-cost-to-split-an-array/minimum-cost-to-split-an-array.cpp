class Solution {
public:
    int n;
    vector<vector<int>> count;
    int dp[1001];
    long long solve(int i,vector<int>& nums,int k){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans = INT_MAX;
        for(int j = i;j<n;j++){
            ans = min(ans,k + count[i][j] + solve(j+1,nums,k));
        }
        return dp[i] = ans;
    }
    int minCost(vector<int>& nums, int k) {
        n = nums.size();
        unordered_map<int,int> mp;
        memset(dp,-1,sizeof(dp));
        count.resize(n,vector<int>(n));
        for(int i = 0;i<n;i++){
            int cnt = 0;
            mp.clear();
            for(int j = i;j<n;j++){
                if(mp[nums[j]]==1) cnt--;
                mp[nums[j]]++;
                if(mp[nums[j]]==1) cnt++;
                count[i][j] = (j-i+1) - cnt;
            }
        }
        return solve(0,nums,k);
    }
};