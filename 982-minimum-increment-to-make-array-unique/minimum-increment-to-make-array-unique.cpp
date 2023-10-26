class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto& it : nums) mp[it]++;
        int mv = 1 + (*max_element(nums.begin(),nums.end()));
        set<int> free;
        int me = *min_element(nums.begin(),nums.end());
      //  cout << me << " " << mv << endl;
        for(int i = me+1;i<mv;i++) if(mp.find(i)==mp.end()) free.insert(i);
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            if(mp[nums[i]]>1){
                mp[nums[i]]--;
                auto it = free.upper_bound(nums[i]);
                int a = *it;
                if(it==free.end()){
                    cnt += (mv-nums[i]);
                    mv++;
                }
                else{
                    cnt += (a - nums[i]);
                    free.erase(it);
                }
            }
        }
        return cnt;
    }
};