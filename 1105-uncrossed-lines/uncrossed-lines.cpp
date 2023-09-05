class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2){
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]){
            return dp[i][j] = max({1 + solve(i+1,j+1,nums1,nums2),solve(i+1,j,nums1,nums2),solve(i,j+1,nums1,nums2)});
        }
        return dp[i][j] = max(solve(i+1,j,nums1,nums2),solve(i,j+1,nums1,nums2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1,nums2);
    }
};