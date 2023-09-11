class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        for(int i = 0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int>& temp = it.second;
            int a = it.first;
            int n = temp.size()/a;
            int i = 0;
            while(n--){
                vector<int> t;
                for(int j = i;j<a+i;j++){
                    t.push_back(temp[j]);
                }
                ans.push_back(t);
                i = a+i;
            }
        }
        return ans;
    }
};