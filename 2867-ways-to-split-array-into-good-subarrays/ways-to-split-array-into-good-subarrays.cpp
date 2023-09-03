class Solution {
public:
     int n;
    // int solve(int i,bool has1,vector<int>& nums){
    //     if(i==n) return 0;
    //     int ans = 0;
    //     if(!has1){

    //     }
    //     for(int j = i;j<)
    // }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int c1 = 0;
        vector<int> v;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
                c1++;
                v.push_back(i);
            }
        }
        if(c1==0) return 0;
        if(c1==1) return 1;
        long long ans = 1;
        for(int i = 1;i<v.size();i++){
            ans =  ((ans%1000000007)*(v[i]-v[i-1]))%1000000007;
        }
        return ans%1000000007;
    }
};