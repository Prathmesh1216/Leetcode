class Solution {
public:
    int maxScore(string s) {
        int c1 = 0;
        for(int i = 0;i<s.length();i++) c1 += (s[i]-'0');
        int ans = 0;
        int c0 = 0;
        for(int i = 0;i<s.length()-1;i++){
            if(s[i]=='0') c0++;
            else c1--;
            ans = max(ans,c0+c1);
        }
        return ans;
    }
};