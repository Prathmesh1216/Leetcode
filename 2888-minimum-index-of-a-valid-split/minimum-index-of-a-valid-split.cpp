class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp,mp1;
        int n = nums.size();
        for(int& it : nums) mp[it]++;
        for(int i = 0;i<n-1;i++){
            mp1[nums[i]]++;
            if(2*mp1[nums[i]]>i+1 && 2*(mp[nums[i]]-mp1[nums[i]])>n-i-1) return i;
        }
        return -1;

    }
};