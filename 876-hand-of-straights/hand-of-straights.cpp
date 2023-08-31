class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k) return false;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }   
        int cnt = 0;     
        int i=  0;
        while(i<nums.size() && mp.size()>0){
            if(mp.find(nums[i])!=mp.end()){
                cnt++;
                int s = 1;
                int a = nums[i];
                int b = k;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                while(s<k){
                    if(mp.find(a+1)==mp.end()) return false;
                    mp[a+1]--;
                    if(mp[a+1]==0) mp.erase(a+1);
                    s++;
                    a++;
                }
            }
            i++;
        }
        if(cnt!=n/k) return false;
        return true;
    }
};