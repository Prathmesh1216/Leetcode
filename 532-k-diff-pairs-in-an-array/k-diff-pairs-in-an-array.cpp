class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0){
            int ans = 0;
            unordered_map<int,int> mp;
            for(auto& it : nums){
                mp[it]++;
                if(mp[it]>=2) ans++,mp[it]=-123456789;
            }
            return ans;
        }
        set<int> st(nums.begin(),nums.end());
        for(auto& it : nums) cout << it << " ";
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto it : st){
            ans += mp[it-k];
            mp[it]++;
        }
        return ans;
    }
};