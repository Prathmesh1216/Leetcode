class Solution {
public:
    int n;
    map<int,int> mp;
    int dp[20001];
    int solve(int i,vector<int>& nums){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans1 = 0,ans2 = 0;
        int j = i+1;
        int k = i;
        while(j<n){
            if(nums[j]>nums[i]+1) break;
            j++;
        }
        while(k<n && nums[k]==nums[i]){
            k++;
        }
        ans1 = solve(k,nums);
        ans2 = mp[nums[i]] + solve(j,nums);
        return dp[i] = max(ans1,ans2);
    }
    int deleteAndEarn(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        for(auto it : nums){
            mp[it] += it;
        }
        return solve(0,nums);
    }
};