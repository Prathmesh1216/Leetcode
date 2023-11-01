class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int c0 = 0;
        long long prod = 1;
        for(int i = 0;i<nums.size();i++) if(nums[i]!=0) prod*= nums[i];else c0++;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                if(c0>0) ans.push_back(0);
                else ans.push_back(prod/nums[i]);
            }
            else{
                if(c0==1) ans.push_back(prod);
                else ans.push_back(0);
            }
        }
        return ans;
    }
};