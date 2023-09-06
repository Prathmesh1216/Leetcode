class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<nums.size()){
            while(abs(nums[i]-nums[j])>2*k){
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;

    }
};