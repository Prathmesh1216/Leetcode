class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> v(26);
        int cnt = 0;
        for(auto& it : s){
            if(!v[it-'a']){
                v[it-'a'] = 1;
                cnt++;
            }
        }
        return cnt;
    }
};