class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mr = 0;
        int n = nums.size();
        if(n==1) return true;
        for(int i = 0;i<nums.size()-1;i++){
            if(mr<i) return false;
            mr = max(mr,i+nums[i]);
            if(mr>=n-1) return true;
        }
        return false;
    }
};