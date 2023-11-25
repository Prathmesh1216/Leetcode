class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n),ss(n);
        for(int i = 1;i<n;i++) ps[i] = ps[i-1] + nums[i-1];
        for(int i = n-2;i>=0;i--) ss[i] = ss[i+1] + nums[i+1];
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            ans[i] = i*(nums[i]) - ps[i] + ss[i] - (n-i-1)*nums[i];
        }
        return ans;
    }
};