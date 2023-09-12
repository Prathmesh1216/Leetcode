class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        
        unordered_map<long long,long long> mp;
        for(auto& it : nums) mp[it]++;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]--;
            for(int j = i+1;j<n;j++){
                mp[nums[j]]--;
                for(int k = j+1;k<n;k++){
                    mp[nums[k]]--;
                    if(mp[(long long)target-nums[i]-nums[j]-nums[k]]>0){
                        vector<int> v = {nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]};
                        sort(v.begin(),v.end());
                        st.insert(v);
                    }
                    mp[nums[k]]++;
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};