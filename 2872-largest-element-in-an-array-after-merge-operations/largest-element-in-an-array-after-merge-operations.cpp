class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        int j = n-2;
        long long ans = 0;
        long long cs = nums[j+1];
        while(j>=0){
            if(cs>=nums[j]){
                cs+=nums[j];
            }
            else{
                ans = max(ans,cs);
                cs = nums[j];
            }
            j--;
        }
        ans = max(ans,cs);
        return ans;
    }
};