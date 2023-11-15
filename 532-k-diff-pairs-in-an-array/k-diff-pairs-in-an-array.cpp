class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int i = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        if(k==0){
            for(auto& it : nums){
                mp[it]++;
            }
            for(auto& it : mp){
                if(it.second>1) ans++;
            }
            return ans;
        }
        while(i<nums.size()){
            ans += mp[nums[i]-k];
            mp[nums[i]]++;
            i++;
            while(i && i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};