class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int l = -1;
        int r = -1;
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==t){
                l = mid;
                end = mid - 1;
            }
            else if(nums[mid]<t){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        start = 0;end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==t){
                r = mid;
                start = mid + 1;
            }
            else if(nums[mid]<t){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return {l,r};
    }
};