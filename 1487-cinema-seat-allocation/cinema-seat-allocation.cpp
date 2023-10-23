class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long tp = 2*n;
        unordered_map<int,set<int>> mp;
        for(auto& it : reservedSeats){
            mp[it[0]].insert(it[1]);
        }
        for(auto& it : mp){
            int cnt = 0;
            bool flag1 = false, flag2 = false;
            if(it.second.find(2)!=it.second.end() || it.second.find(3)!= it.second.end() || it.second.find(4)!=it.second.end() || it.second.find(5)!=it.second.end()) cnt++,flag1 = true;
            if(it.second.find(6)!=it.second.end()|| it.second.find(7)!=it.second.end() ||it.second.find(8)!=it.second.end() || it.second.find(9)!=it.second.end()) cnt++,flag2 = true;
            if(it.second.find(4)==it.second.end() && it.second.find(5)==it.second.end() && it.second.find(6) ==it.second.end() && it.second.find(7)==it.second.end() && (flag1 && flag2)) cnt--;
            tp -= cnt;
        }
        return tp;
    }
};
