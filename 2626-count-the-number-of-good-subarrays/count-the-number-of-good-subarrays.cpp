class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,long long> mp;
        int i = 0;
        int j = 0;
        long long ans = 0;
        int n = nums.size();
        int pairs = 0;
        while(j<n){
            mp[nums[j]]++;
            pairs += mp[nums[j]]-1;
            while(pairs>=k){
                ans += (n-j);
                pairs-=(mp[nums[i]]-1);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
        
    }
};