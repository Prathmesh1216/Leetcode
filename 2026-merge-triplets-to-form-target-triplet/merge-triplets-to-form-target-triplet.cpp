class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<unordered_map<int,int>> v(3);
        vector<int> maxi(3,0);
        bool a = false;
        bool b = false;
        bool c = false;
        for(auto it : triplets){
            if(it[0]<=target[0] && it[1]<=target[1] && it[2]<=target[2]){
                if(it[0]==target[0]) a = true;
                if(it[1]==target[1]) b = true;
                if(it[2]==target[2]) c = true;
            }
        }
        if(a&b&c) return true;
        return false;
    }
};