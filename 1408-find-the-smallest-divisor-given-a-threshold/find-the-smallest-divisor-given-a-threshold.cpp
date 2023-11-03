class Solution {
public:
    bool isValid(int mid,vector<int>& nums,int ts){
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += (nums[i]/mid + (nums[i]%mid!=0));
        }
        return sum<=ts;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = 1e6;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(mid,nums,threshold)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};