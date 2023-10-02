class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int t = *max_element(nums.begin(),nums.end());
        int j = 0,ans = 1,cnt = 0;
        while(j<nums.size()){
            if(nums[j]==t) cnt++;
            else{
                ans = max(ans,cnt);
                cnt = 0;
            }
            j++;
        }
        ans = max(ans,cnt);
        return ans;
    }
};