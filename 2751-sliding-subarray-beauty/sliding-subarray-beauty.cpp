class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        set<int> st;
        int i = 0;int j = 0;
        unordered_map<int,int> mp;
        vector<int> ans;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(j-i+1==k){
                int g = 0;
                for(int k = -50;k<0;k++){
                    if(mp.find(k)!=mp.end()) g+= mp[k];
                    if(g>=x){
                        ans.push_back(k);
                        break;
                    }
                }
                if(g<x) ans.push_back(0);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }  
        return ans; 
    }
};