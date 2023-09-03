class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ps(n);
        ps[0] = nums[0];
        for(int i = 1;i<n;i++){
            ps[i] += ps[i-1]+nums[i];
        }
        vector<long long> sums;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                sums.push_back(ps[j]-ps[i]+nums[i]);
            }
        }
       for(auto it : nums) sums.push_back(it);
       // for(auto it : sums) cout << it << endl;
        sort(sums.begin(),sums.end());
        //return 0;
        long long ans  = accumulate(sums.begin()+left-1,sums.begin()+right,0*1LL);
        return ans%1000000007;

    }
};