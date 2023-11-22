class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i = 0;i<nums.size();i++){
            auto it  = lower_bound(v.begin(),v.end(),nums[i]) - v.begin();
            if(it==v.size()) v.push_back(nums[i]);
            else v[it] = nums[i];
        }
        return v.size();
    }
};