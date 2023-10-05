class Solution {
public:
    int solve(vector<int>& nums,int k){
        int i = 0;
        int j = 0;
        int n = nums.size();
        if(k==0) return 0;
        unordered_map<int,int> mp;
        int cnt = 0;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};