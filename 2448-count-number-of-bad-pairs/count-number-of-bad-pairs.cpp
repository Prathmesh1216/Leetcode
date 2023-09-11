class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        long long ans = 0;
        for(int j = 0;j<n;j++){
            ans += j- mp[nums[j]-j];
            mp[nums[j]-j]++;
        }
        return ans;
    }
};