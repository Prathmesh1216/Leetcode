class Solution {
public:
    int n;
    long long maximumOr(vector<int>& nums, int k) {
        n = nums.size();
        vector<int> ps(n),ss(n);
        for(int i = 1;i<n;i++){
            ps[i] = nums[i-1]|ps[i-1];
        }
        for(int i = n-2;i>=0;i--){
            ss[i] = nums[i+1]|ss[i+1];
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,ps[i]|(((int)pow(2,k)*1LL*nums[i]))|ss[i]);
        }
        return ans;
    }
};