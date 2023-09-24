class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0;
        int j = 0;
        if(spaces[0]==0) ans += ' ',j++;
        while(i<s.length()){
            ans += s[i];
            if(j<spaces.size() && spaces[j]-1==i){
                ans += ' ';
                j++;
            }
            i++;
        }
        return ans;
    }
};