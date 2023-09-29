class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> v(n);
        int m = 1e9+7;
        long long ans = 0;
        v[0] = 0;
        for(int i = 1;i<n;i++){
            v[i] = (2*v[i-1] + nums[i-1])%m;
        }
        for(int i = 0;i<n;i++){
            v[i] += nums[i]%m;
        }
        for(int i = 0;i<n;i++){
            ans += (1LL*(nums[i]*(nums[i]*v[i]%m)%m)%m)%m;
        }
        return ans%m;

    }
};