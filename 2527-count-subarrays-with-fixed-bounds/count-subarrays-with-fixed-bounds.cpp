class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mnk, int mxk) {
                long long cnt = 0;
        int mini = -1;
        int maxi = -1;
        int start = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]<mnk || nums[i]>mxk){
                start = i+1;
                mini = -1;
                maxi = -1;
            }
            if(nums[i]==mnk){
                mini = i;
            }
            if(nums[i]==mxk){
                maxi = i;
            }
            if(mini!=-1 && maxi!=-1){
                cnt += (min(mini,maxi)-start+1);
            } 
        }
        return cnt;
    }
};