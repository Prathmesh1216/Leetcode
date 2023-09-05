class Solution {
public:
    int rev(int n){
        int ans = n%10;
        n = n/10;
        while(n>0){
            ans *= 10;
            ans += (n%10);
            n/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]-rev(nums[i])]++;
        }
        long long ans = 0;
        for(auto it : mp){
            ans += ((1LL*(it.second)*(it.second-1))/2);
        }
        return ans%1000000007;
    }
};