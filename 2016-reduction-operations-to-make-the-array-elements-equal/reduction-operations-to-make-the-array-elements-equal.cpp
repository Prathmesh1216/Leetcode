class Solution {
public:
    int lo(vector<int>& nums,int ele){
        int start = 0;
        int end = nums.size()-1;
        int n = nums.size();
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]<=ele){
                ans  = n - mid - 1;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        while(i<n){
            cnt += (lo(nums,nums[i]));
            i++;
            while(i&& i<n &&  nums[i]==nums[i-1]) i++;
        }
        return cnt;
    }
};