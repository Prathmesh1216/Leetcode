class Solution {
public:
    int solve(vector<int>& nums,int t){
        if(t<0) return 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        while(j<n){
            sum += nums[j];
            while(sum>t){
                sum-=nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return solve(nums,goal)-solve(nums,goal-1);    
    }
};