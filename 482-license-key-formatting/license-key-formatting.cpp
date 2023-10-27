class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t = "";
        for(int i = 0;i<s.length();i++){
            if(s[i]!='-') t += toupper(s[i]);
        }
        string ans = "";
        int i = t.length()-1;
        while(i>=0){
            int a = k;
            while(a>0 && i>=0){
                ans += t[i];
                i--;
                a--;
            }
            ans += '-';
        }
        if(ans.length()==0) return "";
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};