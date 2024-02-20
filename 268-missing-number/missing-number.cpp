class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        long s = (n*(n+1))/2;
        return s - sum;
    }
};