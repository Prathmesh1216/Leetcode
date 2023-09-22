class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        for(auto& it : rectangles){
            mp[{it[0],it[1]}]++;
            mp[{it[0],it[3]}]--;
            mp[{it[2],it[1]}]--;
            mp[{it[2],it[3]}]++;
        }
        int ans = 0;
        for(auto& it : mp){
            if(it.second!=0){
                if(abs(it.second)!=1) return false;
                ans ++;
            }
        }
        return ans==4;
    }

};