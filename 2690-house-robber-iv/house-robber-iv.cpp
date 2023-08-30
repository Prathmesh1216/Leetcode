class Solution {
public:
    bool isValid(int mid,vector<int>& nums,int k){
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }

        }
        if(cnt>=k) return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int start = 0;
        int end = v.size()-1;
        int ans = -1;
        while(start<=end){
            int mid  = start + (end-start)/2;
            if(isValid(v[mid],nums,k)){
                ans = v[mid];
                end = mid -1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};