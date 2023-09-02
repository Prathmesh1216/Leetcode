class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        long long sum = 0;
        int j = 0;
        while(j<nums.size()){
            sum += nums[j];
            if(mp.find(sum%k)!=mp.end()){
                if(mp[sum%k]!=j-1) return true;
            }
            else mp[sum%k] = j;
            j++;
        }
        return false;

    }
};