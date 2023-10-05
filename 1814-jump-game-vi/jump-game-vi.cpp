class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
         int n = nums.size();
         vector<int> dp(n,-123456789);
         multiset<int> st;
         st.insert(nums[0]);
         dp[0] = nums[0];
         for(int i = 1;i<n;i++){
             if(i>k){
                 st.erase(st.find(dp[i-k-1]));
             }
            st.insert(dp[i] = *(--st.end()) + nums[i]);
         }
         return dp[n-1];
    }
};