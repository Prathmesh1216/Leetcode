class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
       // int lastmin = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) continue;
            long long parts = nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0){
                parts++;
            }
            ans += parts-1;
            nums[i] = nums[i]/parts;
        }
        return ans;
    }
};