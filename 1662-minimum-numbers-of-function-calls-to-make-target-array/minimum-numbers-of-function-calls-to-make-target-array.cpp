class Solution {
public:
    int steps(int n){
        if(n==0) return 0;
        int ans = 0;
        if(n&1) n--,ans++;
        ans += steps(n/2);
        return ans;
    }
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            cnt += steps(nums[i]);
        }
        int me = *max_element(nums.begin(),nums.end());
        if(me) cnt += log2(me);
        return cnt;
    }
};