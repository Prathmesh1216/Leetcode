class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;
        int c = 0;
        while(j<nums.size()){
            if(nums[j]==0) c++;
            while(c>1){
                if(nums[i]==0) c--;
                i++;
            }
            ans = max(ans,j-i);
            j++;
        }
        return ans;
    }
};