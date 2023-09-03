class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int maxi = -123456789;
        int cnt = 0;
        for(int i = 0;i<nums.size()-1;i++){
            
            if(nums[i]>nums[i+1]){
                cnt++;
                if(cnt>1) return false;
                if(nums[i+1]<maxi){
                    nums[i+1] = nums[i];
                } 

            } 
            maxi = max(maxi,nums[i]);
        }
        return true;
    }
};