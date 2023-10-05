class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n);
        int cnt = 0;
        ps[0] = nums[0];
        for(int i = 1;i<n;i++){
            ps[i] += (ps[i-1]+nums[i]);
        }
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            if(ps[i]==k) cnt++;
            cnt += mp[ps[i]-k];
            mp[ps[i]]++;
        }
        return cnt;
    }
};