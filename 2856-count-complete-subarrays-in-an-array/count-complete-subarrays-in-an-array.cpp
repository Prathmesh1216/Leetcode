class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        int t = mp.size();
        mp.clear();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                mp[nums[j]]++;
                if(mp.size()==t) cnt++;
            }
            mp.clear();
        }
        return cnt;

    }
};