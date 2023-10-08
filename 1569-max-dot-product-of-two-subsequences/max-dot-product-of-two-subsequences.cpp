class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,bool cnt,vector<int>& nums1,vector<int>& nums2){
        if(i==n || j==m){
            if(cnt==0) return -1e9;
            return 0;
        }
        if(dp[i][j][cnt]!=-123456789) return dp[i][j][cnt];
        return dp[i][j][cnt] =  max({nums1[i]*nums2[j] + solve(i+1,j+1,1,nums1,nums2),solve(i+1,j,cnt,nums1,nums2),solve(i,j+1,cnt,nums1,nums2)});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(),m = nums2.size();
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(2,-123456789)));
        return solve(0,0,0,nums1,nums2);
    }
};