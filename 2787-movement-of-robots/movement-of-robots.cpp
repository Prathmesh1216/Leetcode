class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(s[i]=='L') nums[i]-=d;
            else nums[i]+=d;
        }

        sort(nums.begin(),nums.end());
        vector<long long> ps(n);
        ps[0] = 0;
        for(int i = 1;i<n;i++){
            ps[i] = ps[i-1]+nums[i-1];
        }
        long long ans = 0;
        for(int i = 1;i<n;i++){
            ans += (i*1LL*nums[i]-ps[i])%1000000007;
        }
        return ans%1000000007;
    }
};