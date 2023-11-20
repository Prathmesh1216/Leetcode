class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int indg = 0;
        int indp = 0;
        int indm = 0;
        unordered_map<char,int> mp;
        for(int i = 0;i<garbage.size();i++){
            for(int j = 0;j<garbage[i].length();j++){
                if(garbage[i][j] == 'M'){
                    mp['M']++;
                    indm = i;
                }
                else if(garbage[i][j] == 'P'){
                    mp['P']++;
                    indp = i;
                }
                else if(garbage[i][j] == 'G'){
                    mp['G']++;
                    indg = i;
                }
            }
        }
        // cout << mp['M'] << endl;
        // cout << mp['G'] << endl;
        // cout << mp['P'] << endl;
        int ans = 0;
        for(int i = 0;i<indm;i++){
            ans += travel[i];
        }
        for(int i = 0;i<indp;i++){
            ans += travel[i];
        }
        for(int i = 0;i<indg;i++){
            ans += travel[i];
        }
        // cout << ans << endl;
        ans = ans + mp['M']+ mp['G'] +mp['P'];
        return ans;
    }
};