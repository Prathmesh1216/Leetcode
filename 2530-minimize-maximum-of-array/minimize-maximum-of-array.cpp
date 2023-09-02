class Solution {
public:
    bool isValid(int mid,vector<int>& nums){
        long long csum=0;
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            long long c=(long long)mid*((long long)i+1);
            if(csum>c){
                return false;
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int start = 0;
        int end = *max_element(nums.begin(),nums.end());
        int ans = end;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,nums)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};