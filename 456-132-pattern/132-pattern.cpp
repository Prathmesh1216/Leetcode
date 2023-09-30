class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0] = INT_MAX;
        for(int i = 1;i<n;i++){
            left[i] = min(left[i-1],nums[i-1]);
        }
        set<int> st;
        st.insert(nums[n-1]);
        for(int i = n-2;i>0;i--){
            auto it = st.upper_bound(left[i]);
            if(it==st.end() || *it>=nums[i]) st.insert(nums[i]);
            else return true; 

        }
        return false;
    }
};