class Solution {
public:
    int n,m;
    map<int,int> m1,m2;
    int mod = 1e9+7;
    long long dp[100001][2];
    long long solve(int i,bool arr,vector<int>& nums1,vector<int>& nums2){
        if(!arr){
            if(i>=n) return 0;
        }
        if(arr && i>=m) return 0;
        if(dp[i][arr]!=-1) return dp[i][arr];
        if(!arr){
            long long  ans = 0,ans1 = 0;
            ans = nums1[i]+solve(i+1,arr,nums1,nums2);
            if(m2.find(nums1[i])!=m2.end()) ans1 = nums1[i] + solve(m2[nums1[i]]+1,1,nums1,nums2);
            return dp[i][arr] = max(ans,ans1);
        }
        long long ans = 0,ans1 = 0;
        ans = nums2[i]+solve(i+1,arr,nums1,nums2);
        if(m1.find(nums2[i])!=m1.end()) ans1 = nums2[i] + solve(m1[nums2[i]]+1,0,nums1,nums2);
        return dp[i][arr] = max(ans,ans1);

    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
         n = nums1.size();
         m = nums2.size();
        for(int i = 0;i<n;i++){
            m1[nums1[i]] = i;
        }
        for(int j = 0;j<m;j++){
            m2[nums2[j]] = j;
        }
        long long ans = max(solve(0,1,nums1,nums2),solve(0,0,nums1,nums2));
        return ans%mod;
    }
};