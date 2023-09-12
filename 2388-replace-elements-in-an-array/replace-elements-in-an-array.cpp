class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(auto& it : operations){
            int a = mp[it[0]];
            mp.erase(it[0]);
            mp[it[1]] = a;
        }
        for(auto it : mp){
            nums[it.second] = it.first;
        }
        return nums;
    }
};