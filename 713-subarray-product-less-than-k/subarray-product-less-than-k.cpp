class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int i = 0;
        int j = 0;
        int pd = 1;
        int cnt = 0;
        while(j<nums.size()){
            pd*=nums[j];
            while(i<=j && pd>=k){
                pd /= nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};