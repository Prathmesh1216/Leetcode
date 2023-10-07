class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = nums.size();
        for(auto& it : mp){
            int a = 0;
            for(int i = 1;i<it.second.size();i++){
                a = max(a,(it.second[i] - it.second[i-1])/2);
            }
            ans = min(ans,a);
        }
        return ans;
    }
};