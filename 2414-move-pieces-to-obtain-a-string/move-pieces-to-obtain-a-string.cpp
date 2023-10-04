class Solution {
public:
    bool canChange(string s, string t) {
        int i = 0;
        int j = 0;
        while(i<s.length() || j<t.length()){
           while(s[i]=='_') i++;
           while(t[j]=='_') j++;
           if(s[i]!=t[j]) return false;
           if(s[i]=='R' && i>j) return false;
           if(s[i]=='L' && i<j) return false;
           i++;
           j++;
        }
        return true;

    }
};