class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top()>nums[i] && k-st.size() <= n-i-1) st.pop();
            if(st.size()<k) st.push(nums[i]);
        }
        vector<int> ans;
        while(!st.empty()) ans.push_back(st.top()),st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};