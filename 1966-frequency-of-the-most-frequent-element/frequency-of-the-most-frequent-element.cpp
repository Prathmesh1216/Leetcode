class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0; int j = 0;
        int ans = 0;
        long long sum = 0;
        while(j<n){
            sum += nums[j];
            while((j-i+1)*1LL*nums[j] - sum>k){
                sum-=nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};