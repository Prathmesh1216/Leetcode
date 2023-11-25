class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int tsum = accumulate(nums.begin(),nums.end(),0);
        int csum = 0;
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            ans[i] = i*(nums[i]) - csum + (tsum-csum) - (n-i)*nums[i];
            csum += nums[i];
        }
        return ans;
    }
};