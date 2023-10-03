class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        set<int> st;
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        while(j<nums.size()){
            st.insert(nums[j]);
            mp[nums[j]]++;
            if(j-i+1==k){
                auto it = (--st.end());
                int a = *it;
                ans.push_back(a);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};