class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,set<int>> mp;
        for(auto& it : logs){
            mp[it[0]].insert(it[1]);
        }
        unordered_map<int,int> mp1;
        for(auto it : mp){
            mp1[it.second.size()]++;
        }
        vector<int> ans(k);
        for(int i = 0;i<k;i++){
            ans[i] = mp1[i+1];
        }
        return ans;
    }
};