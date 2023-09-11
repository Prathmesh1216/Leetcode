class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int sum  = 0;
        int n = nums.size();
        while(j<n){
            if(sum>nums[j]) return false;
            nums[j]-=sum;
            sum += nums[j];
            if(j-i+1==k){
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return sum==0;
     }
};