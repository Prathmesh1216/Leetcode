class Solution {
public:
    int solve(vector<int>& nums,int k){
        int c1 = 0;
        int c2 = 0;
        int maxi = -1;
        int i = 0;
        int j = 0;
        while(j<nums.size()){
            if(nums[j]>k){
                i = j + 1;
            }
            else{
                c1 += (j-i+1);
            }
            j++;
        }
        return c1;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return solve(nums,right)-solve(nums,left-1); 
    }
};