class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        int i = 0;
        while(i<nums.size()){
            int j = i;
            long long temp = 0;
            while(j<nums.size() && nums[j]==0){
                temp++;
                j++;
            }
            cnt += (temp*(temp+1))/2;
            i = j+1;

        }
        return cnt;
    }
};