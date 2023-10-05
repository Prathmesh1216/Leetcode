class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        long long cnt = 0;
        int n = nums.size();
        int i = 0;
        int j = 1;
        int l = nums[0];
        while(j<n){
            if(nums[j-1]-nums[j]==1){
                cnt += (j-i);
            }
            else{
                i = j;
            }
            j++;
        }
        return cnt+n;
    }
};