class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                int t = nums[i-1] - nums[i] + 1;
                cnt += t;
                nums[i] += t;
            }
        }
        return cnt;
    }
};