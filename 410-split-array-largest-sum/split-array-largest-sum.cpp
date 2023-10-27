class Solution {
public:
    bool isValid(int mid,vector<int>& nums,int k){
        int cnt = 1;
        int csum = 0;
        for(int i = 0;i<nums.size();i++){
            csum += nums[i];
            if(csum>mid){
                cnt++;
                csum = nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,nums,k)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};