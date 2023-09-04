class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int> mp;
        int ans = INT_MAX;
        int maxi = 0;
        for(auto it : nums){
            mp[it%space]++;
            maxi = max(maxi,mp[it%space]);
        }
        for(auto it :  nums){
            if(mp[it%space]==maxi) ans = min(ans,it);
        }
        return ans;
    }
};