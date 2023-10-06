class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i = 0;
        int cnt = 0;
        if(nums.size()<3) return 0;
        while(i<nums.size()-1){
            int j = i+1;
            int d = nums[j]-nums[i];
            int t = 1.;
            while(j<nums.size() && nums[j]-nums[j-1]==d){
                t++;j++;
            }
            cnt += ((t-1)*(t-2))/2;
            i = j-1;
        }
        return cnt;
    }
};